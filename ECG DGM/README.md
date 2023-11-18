# MCC1_IFSC_2023_02

<h1 id="nome-do-produto--ecg-dgs"><em> Eletrocardiograma DGS</em></h1>
<h2 id="descrição">Descrição:</h2>
<p>O <strong>ECG DGS</strong> é um dispositivo portátil de monitoramento cardíaco que permite aos usuários monitorar com facilidade e precisão a saúde do coração. Este dispositivo é ideal para uso doméstico, bem como para profissionais médicos que desejam um ECG portátil para testes rápidos e precisos.</p>
<h2 id="circuito-de-aquisição-de-sinal">Circuito de Aquisição de Sinal:</h2>
<p>Utiliza o módulo ECG AD8232 para capturar com alta precisão os sinais elétricos do coração do usuário.
Acompanhado por um conjunto de eletrodos fácil de usar que garantem uma recepção adequada do sinal.</p>
<h2 id="fortalecimento-e-condicionamento">Fortalecimento e Condicionamento:</h2>
<p>Amplifica e condiciona os sinais de ECG para aprimorar a qualidade do sinal, eliminando interferências.
Garante leituras precisas mesmo em ambientes ruidosos.</p>
<h2 id="conversão-analógico-digital-adc">Conversão Analógico-Digital (ADC):</h2>
<p>O microcontrolador KL05Z realiza a conversão precisa de sinais analógicos em dados digitais de alta resolução.
Facilita a eficiente recepção e processamento de sinais.</p>
<h2 id="processamento-e-análise">Processamento e Análise:</h2>
<p>Incorpora algoritmos de processamento de sinal avançados para análise em tempo real dos dados capturados.
Resultados exibidos no próprio Smartphone fazendo uso do aplicativo desenvolvido inteiramente para a verificação dos dados repassados pelo ECG DGS.</p>
<h2 id="comunicaçõesarmazenamento">Comunicações/Armazenamento:</h2>
<p>Os dados de ECG podem ser armazenados internamente ou transmitidos para um aplicativo móvel via conexão Bluetooth.
Os usuários podem acompanhar o histórico de leituras e compartilhá-lo com profissionais médicos.</p>
<h2 id="características-adicionais">Características Adicionais:</h2>
<p>Interface de usuário intuitiva no display, fornecendo informações claras sobre a condição cardíaca do usuário.
Alertas visuais para detecção de arritmia cardíaca.
Bateria recarregável via USB, garantindo uma longa duração.
Design compacto e leve, facilitando a portabilidade.</p>
<h2 id="aplicações">Aplicações:</h2>
<p>Monitoramento domiciliar de pacientes com cardiopatia crônica.
Monitoramento cardíaco durante atividades esportivas e exercícios.
Uso em ambientes clínicos para <strong>testes rápidos</strong>.</p>
<p>O ECG DGS é uma solução <strong>inovadora</strong> e acessível de monitoramento cardíaco que capacita os usuários a tomar medidas proativas para melhorar sua saúde cardiovascular. Além disso, fornece aos profissionais de saúde uma ferramenta útil em sua prática diária. Este conceito pode servir como base para o desenvolvimento de produtos reais, cumprindo os mais altos padrões de qualidade, segurança e regulamentações aplicáveis.</p>
____________

##  DESIGN

No design, especificaremos os modelos e as especificações para cada tipo de tecnologia, bem como suas interações com o módulo de controle e os componentes adicionais necessários para que o circuito opere corretamente. Esse processo será dividido em três etapas: *Especificações e Modelos, Maquete Eletrônica  e Diagrama de Funcionamento.*

## Especificações e Modelos

MODELO| 
---------|
Microcontrolador FRDM-KL05Z.|
Módulo Bluetooth RS232 HC-05. |
Módulo ECG AD8232. |
Bateria 9v |
Aplicativo |

____________
  
### Microcontrolador
FRDM-KL05Z:

![image](https://github.com/SarahBararua/Microcontroladores/assets/74320017/adcf9d32-b11c-4042-af13-dcdabedb9654)

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
 
 ____________ 

### Sensor Bluetooth
Módulo Bluetooth RS232 HC-05:

![Captura de tela de 2023-11-05 12-57-37](https://github.com/SarahBararua/Microcontroladores/assets/74320017/7a54b5ad-c9cc-48ed-a4fb-9c5cc02e6510)

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
* 
____________

### Sensor Cardiaco 
Módulo ECG AD8232:

![image](https://github.com/SarahBararua/Microcontroladores/assets/74320017/325e6b44-f854-480a-bea0-c62d5a99ebc4)

**Especificações:**

* Modelo: AD8232
* Marca: OEM
* Pulso e Frequência Cardíaca
* Tensão de operação: 3.3V
* Temperatura de operação: -40°C a +85°C
* Módulo de processamento
* Eletrodo 3 vias conector 3,5mm
* Comprimento do cabo: 50cm
* Fácil conexão com o microcontrolador
* Medição de atividade elétrica do coração
* ECG portátil
* LED indicador de pulsos e batimentos
* Saída Analógica;
* Material: Termoplásticos/Nylon/Metal
* Origem: China
* Tamanho (Módulo): 35mm Largura x 28mm Profundidade x 10mm Altura 
* Tamanho: 130mm Largura x 80mm Profundidade x 25mm Altura 
* Peso: 30g

____________

### Maquete Eletrônica  
![Captura de tela de 2023-11-06 10-12-31](https://github.com/SarahBararua/Microcontroladores/assets/74320017/c111c4d2-0d76-4e97-847a-89996a2a33bb)

____________
### Diagrama de Funcionamento

![image](https://github.com/SarahBararua/Microcontroladores/assets/74320017/9b54f481-d114-4bc6-92f4-970f6e810715)

____________
### Pinos
Os pinos responsáveis por conectar o ECG ao KL05z são de natureza analógica, e o propósito do microcontrolador é converter esses sinais analógicos em saída digital para serem enviados aos pinos do dispositivo Bluetooth.

No caso específico do FRDM-KL05Z, os pinos A0-A5 são destinados às entradas analógicas. Esses pinos são conectados ao conversor analógico-digital (ADC) do microcontrolador, permitindo a leitura de sinais analógicos.

Para fazer a ligação do módulo Blurtooth os pinos 0 e 1 do microcontrolador FRDM-KL05Z serão utilizados, esses geralmente são associados à funcionalidade de comunicação serial assíncrona (UART - Universal Asynchronous Receiver-Transmitter). Porém é importante ressaltar que é possível utilizar outros pinos do microcontrolador para a conexão de um módulo Bluetooth, não se restringindo apenas aos pinos 0 e 1.

Entretanto, é importante observar que nenhum dos dois módulos possui uma biblioteca pronta disponível para inclusão direta no código. A biblioteca base que será modificada para uso do módulo ECG é a biblioteca que usa este módulo porém para o Arduino.

É crucial ressaltar que, uma vez que possuímos a informação sobre os pinos envolvidos, é imperativo direcionar nossa atenção prioritariamente para a fase de conversão do sinal analógico para o formato digital.

____________
### Planejamento
* Configuração dos Pinos:

Identificação dos pinos do FRDM-KL05Z que serão conectados aos módulos ECG e Bluetooth.
Utilização das funções adequadas para configurar esses pinos no modo correto (analógico para o ECG e serial para o Bluetooth).

* Inicialização dos Módulos:

a. Módulo ECG (AD8232):

Configuração dos pinos de entrada analógica para a leitura dos sinais do ECG.

Inicialização o ADC (Conversor Analógico-Digital) para processar os sinais analógicos do ECG.

b. Módulo Bluetooth (HC-05):

Configuração dos pinos de comunicação serial (UART) para a comunicação com o módulo Bluetooth.

Inicialização da comunicação UART com as configurações adequadas (baud rate, bits de dados, paridade, etc.).

* Loop Principal:

No loop principal do programa usaremos:

Realização da leitura dos sinais do ECG utilizando o ADC.

O envio dos dados lidos do ECG através do módulo Bluetooth via UART.

Verificação e processamento dos dados recebidos pelo Bluetooth, se houver.

Implementação da lógica de controle, filtragem ou processamento de sinais do ECG.

