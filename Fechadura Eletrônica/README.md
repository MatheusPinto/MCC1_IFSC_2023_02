# MCC1_IFSC_2023_02

## 1. PROPOSTA

Com base na proposta da unidade curricular de Microcontroladores I, foi definido a criação de um projeto de uma fechadura eletrônica inteligente utilizando como módulo de controle o microcontrolador FRDM-KL05Z. Este projeto seguirá a metodologia CDIO, uma abordagem composta por quatro etapas essenciais: Concepção, Design, Implementação e Operação, as quais serão detalhadas ao longo deste documento.

## 2. CONCEPÇÃO

Nesta etapa, a finalidade definir os requisitos e meios para o desenvolvimento de uma fechadura eletrônica que ofereça segurança e confiabilidade ao usuário. Para isso, estruturamos as condições e tecnologias que serão aplicadas ao projeto:

- **Módulo de Controle e Sensores:**
  O núcleo deste projeto reside no uso do microcontrolador FRDM-KL05Z da NPX com instruções pré-programadas para gerenciar todos os sensores e interfaces.

- **Fechadura Eletrônica:**
  Será utilizada uma fechadura eletrônica pronta que é acionada com parâmetros de tensão e corrente pré-definidos.

- **Display Incorporado e Controle por Senha:**
  O controle de senha será realizado por meio de um display touchscreen. A interface UART (Universal Asynchronous Receiver-Transmitter) será utilizada para conectar e controlar o display, permitindo a inserção da senha de forma intuitiva.

- **Controle por Impressão Digital:**
  Faremos uso de interfaces GPIO (General Purpose Input/Output) para conectar e controlar um sensor de impressão digital, permitindo o cadastro e a verificação de impressões digitais.

- **Controle por Cartões de Acesso:**
  A interface SPI (Serial Peripheral Interface) será utilizada para conectar um sensor RFID, possibilitando a identificação de cartões eletrônicos cadastrados.

- **Sinalização por Alarme:**
  Para o alarme sonoro, utilizaremos GPIO para controlar um buzzer e gerar alertas sonoros quando necessário.

- **Conectividade com Dispositivos Externos:**
  A interface Bluetooth, que pode ser UART ou SPI, será usada para possibilitar a comunicação com dispositivos externos, como smartphones e computadores.

- **Fonte de Alimentação:**
  A fechadura operará com uma fonte de alimentação de corrente contínua de 12V.

Com base nas tecnologias propostas, o objetivo final deste projeto é criar um sistema de controle dinâmico que utilize diversas plataformas de acesso, tornando a comunicação com o usuário mais eficaz e aumentando a segurança. No decorrer do documento, detalharemos as tecnologias específicas a serem implementadas em cada uma dessas interfaces.

Tabela de requisitos:
____________

| REQUISITOS                           | TIPO DE TECNOLOGIA        | QUANTIDADE |
|--------------------------------------|---------------------------|------------|
| Controle por Cartões de Acesso       | Sensor RFID               | 1          |
| Conectividade com Dispositivos Externos | Módulo Bluetooth        | 1          |
| Sinalização por Alarme               | Buzzer                    | 1          |
| Display Incorporado e Controle por Senha | Display Touchscreen     | 1          |
| Controle por Impressão Digital      | Sensor Biométrico         | 1          |
| Módulo de Controle e Sensores        | Microcontrolador FRDM-KL05Z | 1        |
| Fonte de Alimentação                 | Fonte 12V                 | 1          |
| Fechadura                            | Fechadura Eletrônica      | 1          |` 
____________

## 3. DESIGN


No design especificaremos os modelos e especificações para cada tipo de tecnologia , suas interações com o módulo de controle e os componentes adicionais indispensáveis para o circuito operar corretamente.
  ____________
MODELO:| PREÇO (R$): |
---------|----------| 
Leitor RFID RDM6300 125KHz.|25,00 |
Módulo Bluetooth RS 232 HC-05. | 39,90 | 
Buzzer Ativo 5V. | 3,90 | 
Display Gráfico 2.4 TFT - ILI9341. |56,10 | 
Leitor Biométrico impressão digital Dymore FPM10A DY50. | 110,00 |
Microcontrolador FRDM-KL05Z.| 118,00 |
Relé 2 Canais JQC-3FF-S-Z. | 15,00 |
Resistor 220Ω 5% 1/4W. | 0,10 |
Resistor 100Ω 5% 1/4W.| 0,10| 
  ____________

### 3.1 Sensor RFID
Leitor RFID RDM6300 125KHz.

**Especificações:**

 * Módulo RFID RDM630;
* Tensão de operação: 5V DC;
* Corrente: <50mA;
* Frequência 125KHz;
* Interface: TTL RS232;
* Antena externa;
* Dimensões antena: 46 x 32 x 3mm;
* Dimensões módulo: 38.5 x 19 x 9mm.

![](https://ae01.alicdn.com/kf/H3e34afccfe164f40a14cde21ed647bed0/WAVGAT-RFID-M-dulo-Leitor-para-Arduino-UART-Output-Access-Control-System-Melhores-Pre-os-125Khz.jpg)

### 3.2 Sensor Bluetooth
Módulo Bluetooth RS232 HC-05.

**Especificações:**

* Protocolo Bluetooth: 3.0;
* Frequência: 2,4GHz Banda ISM;
* Modulação: GFSK;
* Emissão de energia: <=4dBm, Classe 2;
* Sensibilidade: <=84dBm com 0,1% BER;
* Velocidade Assíncrono: 2,1Mbps(Max)/160Kbps;
* Velocidade Síncrono: 1Mbps/1Mbps;
* Segurança: Autentificação e Encriptação;
* Perfil: Porta Serial Bluetooth;
* Suporta modo Escravo (Slave) e Mestre (Master);
* CSR chip: Bluetooth v2.0;
* Banda de Onda: 2,4Hhz-2,8Ghz, Banda ISM;
* Tensão: 3,3v (2,7-4.2v);
* Corrente: Pareado 35mA; Conectado 8mA;
* Temperatura: -40 ~ +105°C;
* Alcance: 10m;
* Baud Rate: 4800;9600;19200;38400;57600;115200;230400;460800;921600;1382400;
* Dimensões: 26,9 x 13 x 2,2mm;
* Peso: 9,6g.

![](https://uploads.filipeflop.com/2017/07/02-30.png)

### 3.3 Buzzer
Buzzer Ativo 5V.

**Especificações:**

* Buzzer tipo ativo;
* Tensão de operação: 4 à 8VDC;
* Corrente de operação: 30mA;
* Saída de som mínima (a 10cm): 85dB;
* Frequência de ressonância: 2300±300 Hz;
* Temperatura de operação: -27 a +70 °C;
* Material: ABS;
* Cor: Preto;
* Dimensões: 11,8 x 9mm.


![](https://www.soldafria.com.br/image/cache/catalog/buzzer-12_mm-com-oscilador-interno-550x550.jpg)

### 3.4 Display Gráfico
Display gráfico 2.4 TFT - ILI9341.

**Especificações:**

 * Driver: ILI9341;
 * Tensão de trabalho: 5,0 V;
 * Tensão lógica: 3,3 - 5,0 V;
 * Corrente do backlight: 80 mA (máx);
 * Dimensão do visor: 2.4 polegadas;
 * Resolução: 240 x 320 pixels;
 * Cor: 18 bits (262 mil tons diferentes);
 * Backlight Branco;
 * Touch Screen Resistivo;
 * Dimensão do visor: 1,6 pol;
 * Dimensão total: 71 x 52 x 8 mm (C x L x A).

![](https://contestimg.wish.com/api/webimage/5b1f90d41845392332b24da0-large.jpg?cache_buster=d5b49a140ba864d4801892a4d64bcf9e)

### 3.5 Sensor Biométrico
Leitor Biométrico impressão digital Dymore FPM10A DY50. 

**Especificações:**

* Tensão de alimentação: 3.3V;
* Corrente de alimentação: <120mA;
* Pico de corrente: <140mA;
* Tempo de imagem da impressão digital: <1.0 segundos;
* Dimensões da janela: 14 x 18 mm;
* Modo de correspondência: modo de correspondência (1: 1);
* Modo de pesquisa (1: N);
* Arquivo principal: 256 bytes;
* Arquivo de modelos: 512 bytes;
* Capacidade de armazenamento: 162 bytes;
* Nível de segurança: cinco (do mais baixo para o mais alto: 1,2,3,4,5);
* Taxa de falsa aceitação (FAR): <0,001% (nível de segurança 3);
* Taxa de falsa rejeição (FRR): <1,0% (nível de segurança 3);
* Tempo de pesquisa: <1,0 segundos (1: 500, a média);
* Interface PC: UART (nível lógico TTL) ou USB2.0/USB1.1;
* Comunicação baud rate (UART): (9600 x N) bps onde N = 1 ~ 12 (valor padrão N = 6, ie 57600bps);
* Ambiente de funcionamento:
  * Temperatura: -20 graus Celsius - +50 graus Celsius
  * Humidade relativa: 40% HR-85% RH (sem condensação);
* Ambiente de armazenamento:
  * Temperatura: -40 graus Celsius - +85 graus Celsius;
  * Humidade relativa: < 85% H (sem condensação);
* Dimensões (C x L x A): 56 x 20 x 21.5 mm.
  
  ![](https://http2.mlstatic.com/D_NQ_NP_945939-MLB31099711565_062019-W.jpg)

### 3.6 Microcontrolador
FRDM-KL05Z.

**Especificações:**

* Microcontrolador: ARM Cortex-M0+ Kinetis da série L;
*   Frequência de operação de 48 MHz;
*   32 KB de Memória Flash;
*   4 KB de Memória RAM;
*   Encapsulamento de 32 pinos QFN;
*   9 Modos de Baixo Consumo;
*   41 sinais GPIO;
*   Interface para Sensor Touch de baixo consumo;
*   Alimentação de energia com 1.8 V (até 1.71 V considerando a tolerância);

*   Comunicação:
    *   1 Módulo SPI;
    *   1 Módulo UART de baixo consumo;
    *   1 Módulo I2C;
*   Módulos Analógicos:
    *   Conversor Analógico-Digital SAR de 12-bits;
    *   Conversor Digital-Analógico de 12-bit;
*   Timers:
    *   Timer/PWM de 6 canais;
    *   1 Módulo Timer/PWM de 2 canais;
    *   Relógio de Tempo Real;
    *   Timer de baixo consumo de 16-bits;
    * Timers de Interrupção Periódica.
  
![](https://www.makerhero.com/wp-content/uploads/2017/07/FRDM-KL05Z.jpg)

### 3.7 Módulo Relé
Relé 2 Canais JQC-3FF-S-Z.

**Especificações:**

* Tensão de operação da bobina: 5VDC;
* Quantidade de relés: 2 relés;
* Acionamento: Baixa tensão;
* Tensão máxima de saída do relé: DC 30V/10A, AC 250V/10A;
* Interface que pode ser controlada por: (8051, AVR, PIC, DSP, ARM,     MSP430, lógica TTL);
* Tensão de sinal: 5VCD (IN1, IN2);
* Corrente de comutação: 10A;
* Modelo do Relé: SRD-05VDC-SL-C;
* LED's de indicação de funcionamento;
* Dimensões: 50mm x 3,9mm X 17mm;
* Peso: 28g.
  
![](https://uploads.filipeflop.com/2013/02/imagem003.png)

### 3.8 Resistores 

**Especificações:**

* Resistor 220Ω 5% 1/4W;
* Resistor 100Ω 5% 1/4W.

![](https://res.cloudinary.com/rsc/image/upload/b_rgb:FFFFFF,c_pad,dpr_1.0,f_auto,q_auto,w_700/c_pad,w_700/R0131772-01)

### 3.9 Componentes e Conexões

