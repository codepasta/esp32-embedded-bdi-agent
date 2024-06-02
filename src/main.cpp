#include <Arduino.h>
#include <stdio.h>
#include <agent.h>
#include "configuration.h"
#include <M5Stack.h>
#include "WiFi.h"

//WiFi connection info
const char* ssid = "NETGEAR27";
const char* password = "chummyiris496";

AgentSettings agent_settings;
BeliefBase * beliefs = agent_settings.get_belief_base();
EventBase * events = agent_settings.get_event_base();
PlanBase * plans = agent_settings.get_plan_base();
IntentionBase * intentions = agent_settings.get_intention_base();
Agent agent(beliefs, events, plans, intentions);


void setup() {
  // put your setup code here, to run once:
  //check https://www.pschatzmann.ch/home/2022/02/14/using-stdio-h-file-operations-on-arduino-esp32-to-access-sd-drives/

  M5.begin();
  Serial.begin(115200);
  Serial.println("Initializing BDI Agent");
  pinMode(39, INPUT);

  WiFi.begin(ssid, password);
  Serial.println(" ");
  // Connection info to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    //delay(500);
    yield();
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address of client
  Serial.println(WiFi.localIP());

  Serial.println("Calling run");
  agent.run();
  Serial.println("Copy pointer");
}

void loop() {
  M5.update();
  agent.run();  
  delay(1000);
  
}
