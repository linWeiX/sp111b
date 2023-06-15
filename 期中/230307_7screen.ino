const byte pin0[4]={0, 1, 2, 3};
const byte pin1[4]={4, 5, 6, 7};
const byte LEDs0[10] = {
    B0000,
    B0001,
    B0010,
    B0011,
    B0100,
    B0101,
    B0110,
    B0111,
    B1000,
    B1001
};
const byte LEDs1[10] = {
    B0000,
    B0001,
    B0010,
    B0011,
    B0100,
    B0101,
    B0110,
    B0111,
    B1000,
    B1001
};
void setup() {
    for (byte i = 0; i < 4; i++){
        pinMode(pin0[i], OUTPUT);
        pinMode(pin1[i], OUTPUT);
    }

}
void loop() {
    for (byte index2 = 0; index2 < 10; index2++){
        for (byte index1 = 0; index1 < 10; index1++){
            for (byte i = 0; i < 4; i++){
                digitalWrite(pin0[i], bitRead(LEDs0[index1], i));
                digitalWrite(pin1[i], bitRead(LEDs0[index2], i));
            }
            delay(1000);
        }
    }
}
