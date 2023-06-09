// int Pinbuzzer = A0; //PINO UTILIZADO PELO BUZZER
int PinLed = D7;        // PINO UTILIZADO PARA O LED
int PinSensor = D1;     // PINO UTILIZADO PELO SENSOR DE GÁS MQ-2
int leitura_sensor = 1; // DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)

void setup()
{
    pinMode(PinSensor, INPUT); // DEFINE O PINO COMO ENTRADA
    // pinMode(Pinbuzzer, OUTPUT); //DEFINE O PINO COMO SAÍDA
    pinMode(PinLed, OUTPUT); // DEFINE O PINO COMO SAÍDA
    Serial.begin(115200);    // INICIALIZA A SERIAL
}
void loop()
{
    int valor_digital = digitalRead(PinSensor); // VARIÁVEL RECEBE O VALOR LIDO NO PINO DIGITAL
    // Serial.print("Leitura: ");                  // EXIBE O TEXTO NO MONITOR SERIAL
    // Serial.println(valor_digital);              // MOSTRA NO MONITOR SERIAL O VALOR LIDO DO PINO DIGITAL
    if (valor_digital == 1) {  // SE O VALOR DIGITAL FOR POSITIVO (1) EXIBE A MENSAGEM DE GÁS DETECTADO
        Serial.println("GÁS DETECTADO!!");
    } else {
        Serial.prinln("GÁS INEXISTENTE");
    }

    if (valor_digital < leitura_sensor)
    { 
        // analogWrite(Pinbuzzer, HIGH); //ATIVA O BUZZER E O MESMO EMITE O SINAL SONORO
        digitalWrite(PinLed, HIGH); // ATIVA O LED
    } else { 
        // analogWrite(Pinbuzzer, LOW);//BUZZER DESLIGADO
        digitalWrite(PinLed, LOW); // DESATIVA O LED
    }
    delay(100); // INTERVALO DE 100 MILISSEGUNDOS
}