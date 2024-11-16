# Circuito com arduíno para medir a umidade do ar 
## Sistema Para Medir A Qualidade Do Ar 
- Um sistema voltado para medir a qualidade do ar e a sua umidade podendo ser utilizado em ambientes que tratam de pacientes com problemas respiratórios pois em doenças tais quais as asma DPOC  e quadros de ate mesmo hipóxia pode ser agravados pela falta de umidade no ar 
### O que foi implementado:
- Um circuito composto por sensores e arduíno que colabora para a manutenção da qualidade do ar  
### Ajudar No Tratamento:
- Voltado para a manutenção da qualidade do ar onde ajudará o tratamento de pacietes com doenças respiratórias. 
## Experimentos:

### Teste No Simulador :
- O teste foi feito no simulador wokwi onde foi feito um sistema em arduíno que utilizando do sensor exibe um aviso caso a umidade do ar esteja em nível alarmante. 


### Resultados dos Testes:

- A tela lcd exibe um aviso perfeitamente  
- No caso de umidade baixa : 
  ![Umidade_Baixa](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/sensor%20baixo%20%20132018.png)
- No caso de umidade normal : 
 ![Umidade_normal](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/foto%20de%20trabalho%20de%20boa%20.png)

## Informações Adicionais
### Hardware Utilizado:
- Arduíno uno (para mandar os comandos de print da tela e interpretar os sinais analógicos dos sensores)
- Sensor DHT-22 (Utilizado para checar a umidade relativa do ambiente)
-  Protoboard (utilizado para faciltar as conexões entre os componentes)
-  Tela LCD 16X2 (utilizado para mandar um aviso caso haja alteração na umidade do ar )
- Fios e cabos (para fazer as conexões entre os componentes)
- ![Circuito](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/sensor%20desligado%20.png)

### Simulação Utilizado:
- A  simulação foi feita  utilizando o site wokwi sendo o link dela : https://wokwi.com/projects/414730818955336705
### Observações:
- O código utilizado para o arduíno fora : 
#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN       
  
#define DHTTYPE DHT22   


 DHT dht(DHTPIN, DHTTYPE);
 



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()  {

  // Inicializa o LCD
  
  lcd.begin(16, 2);
  
  lcd.print("Medindo...");

  // Inicializa o sensor DHT
 
  dht.begin();

  
  pinMode(A5, INPUT);
}

void loop() {
  
  // Lê a umidade do sensor DHT22
  
  float umidade = dht.readHumidity();

  // Verifica se a leitura foi bem-sucedida
  
  if (isnan(umidade)) {
    
    lcd.clear();
    
    lcd.print("Erro no DHT22");
    
    return;
  
  }

  // Exibe a umidade na primeira linha
  
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  
  lcd.print("Umidade: ");
  
  lcd.print(umidade);
  
  lcd.print("%");

  // Verifica se a umidade está abaixo de 50%
  
  if (umidade < 50) {
  
    lcd.setCursor(0, 1);
  
    lcd.print("Alerta! Umid. Baixa");
  
  }

  // Delay de 2 segundos antes de ler novamente
  
  delay(2000);
}

- Onde ele importa as bibliotecas do lcd e do sensor dht-22 inicialmente após isso é feita a medição da umidade e emite um aviso caso a mesma esteja em um nível baixo em destaque estão os prints que serão feitos nos respectivos casos.

## Checklist

- [ ] Código atende às normas do projeto e foi formatado de acordo com as diretrizes.
- [ ] Código foi testado e validado em ambiente de desenvolvimento com hardware real (Arduino, Raspberry Pi, ESP32) ou simulação (tinkercad).
- [ ] Documentação atualizada para refletir as mudanças realizadas.
- [ ] Código escrito e comentado em **C** ou **Python** de acordo com os padrões do projeto.
- [ ] Testes com sensores e atuadores específicos incluídos e detalhados na descrição dos testes.

## Tipo de Mudança

- [ ] Correção de bug
- [x] Nova funcionalidade
- [ ] Alteração de funcionalidade existente
- [ ] Documentação
