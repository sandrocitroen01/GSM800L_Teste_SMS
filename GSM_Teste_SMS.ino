/*
Código: Enviando SMS para celular usando o GCM GPRS SIM800L
Autor:  Lex Luthor
Materiais: Arduino e módulo GSM GPRS SIM800L
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <SoftwareSerial.h>     //Inclusão da biblioteca Serial
SoftwareSerial mySerial(3, 2);  //Cria objeto mySerial passando como parâmetro as portas digitais 3 e 2

void setup() {//Inicio da configuração
  Serial.begin(9600);                              //Inicializa a comunicação serial
  mySerial.begin(9600);                            //Inicializa comunicação entre o SIM800L e o Arduino
  delay(1000);                                     //Intervalo de 1 segundo
  mySerial.println("AT");                          //Teste de conexão
  updateSerial();                                  //Chamada da função updateSerial()
  mySerial.println("AT+CMGF=1");                   //Configuração do modo SMS text
  updateSerial();                                  //Chamada da função updateSerial()
  mySerial.println("AT+CMGS=\"+55XXxxxxxxxxx\"");  //Número de telefone que irá receber a mensagem, “XX” corresponde ao DDD do telefone D
  updateSerial();                                  //Chamada da função updateSerial()
  mySerial.print("Teste de modulo GSM........");   //Texto que será enviado para o usúario
  updateSerial();                                  //Chamada da função updateSerial()
  mySerial.write(26);                              //confirmação das configurações e envio dos dados para comunicação serial.
}//Fim da configuração

void loop() {//Inicio do loop

}//Fim do loop

void updateSerial() {
  while (mySerial.available()) {    //Verifica se a comunicação serial está disponível
    Serial.write(mySerial.read());  //Realiza leitura serial dos dados de entrada Arduino
  }
  delay(500);  //Intervalo de 0,5 segundos
}
