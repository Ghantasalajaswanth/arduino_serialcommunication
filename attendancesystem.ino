struct Member {
  String name;
  int status; // 1 for present, 0 for absent
};

Member members[18] = {
   {"kavya", 1}, {"suresh", 1}, {"shankar", 1}, {"swarith", 1}, {"yuvaraj", 1},
  {"akhila", 1}, {"likitha", 1}, {"harshitha", 1}, {"navya charitha ram", 1}, {"sasikanth", 1},
  {"mounika", 1}, {"jose promod", 0}, {"navya sri", 1}, {"jaswanth", 1}, {"priyanka", 1},
  {"uttam", 1}, {"manikanta", 1}, {"kaleswararao", 1}

};

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    int separatorIndex = command.indexOf(',');
    if (separatorIndex != -1) {
      String action = command.substring(0, separatorIndex);
      command = command.substring(separatorIndex + 1);
      int memberID = command.toInt();

      if (action == "GET") {
        if (memberID >= 1 && memberID <= 18) {
          Serial.print(members[memberID - 1].name);
          Serial.print(",");
          Serial.print(members[memberID - 1].status);
        } else {
          Serial.print("Invalid,-1");
        }
        Serial.println();
      } else if (action == "UPDATE") {
        separatorIndex = command.indexOf(',');
        if (separatorIndex != -1) {
          int status = command.substring(separatorIndex + 1).toInt();
          memberID = command.substring(0, separatorIndex).toInt();

          if (memberID >= 1 && memberID <= 18 && (status == 0 || status == 1)) {
            members[memberID - 1].status = status;
            Serial.println("Update successful");
          } else {
            Serial.println("Invalid ID or status");
          }
        }
      }
    }
  }
}
