//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;
//variaveis do botão
const int botao1 = 2;
const int botao2 = 3;



//variaveis de armazenamento de número 




unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;

//Tempo de delay para poder clicar o botão de novo
const int botaoDelay = 100;

void setup()
  // deifinir as portas do arduino como entrada ou saida
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  pinMode(botao1, INPUT);
  	pinMode(botao2, INPUT);
  //configura a taxa de dados para 9600 bps
  Serial.begin(9600);
	//dados para mostrar no monitor serial
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: DripGroup              ");
}

void loop()
{

// configuração dos botões de quando eles delvem ligar e
  // de que forma e as suas informações para o monitor serial
   if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
      Serial.println("botao 1 apertado");
     digitalWrite(vermelho, HIGH);
    ledVermelho();
      lastDebounceTime1 = millis();
   }

   
  
   if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){
      Serial.println("botao 2 apertado");
     digitalWrite(vermelho,LOW);
     ledVermelho();
      lastDebounceTime2 = millis();
     
    // Defini que a led verde ligue se a luminosidade estiver maior que 5
     
   }
  if(getLuminosidade() > 5){
    ledVerde(true);
    Serial.println("luminosidade acima do ideal");
  }else{
    ledVerde(false);
    Serial.println("luminosidade ok");
    
    //defini que a led ligue se a temperatura passar de 15.
}
  if(getTemperatura() > 15){
    ledAzul(true);
    Serial.println("temperatura acima do ideal");
  }else{
ledAzul(false);
    Serial.println("temperatura ok");
    
                  
  }
  delay(10);
}

//funções que não devem retornar nenhuma informação para sua função chamada
void ledVermelho(){
  
}
void ledVerde(bool estado){
  digitalWrite(verde,estado);
}
void ledAzul(bool estado){
	digitalWrite(azul,estado);
    
}
//Configurações do sensor de temperatura e luminosidade
int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
    
} 

int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
