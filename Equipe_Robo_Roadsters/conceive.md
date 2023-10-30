# 1. CONCEPÇÃO DO PROJETO

Vivemos em uma era de soluções cada vez mais complexas para problemas cada vez mais específicos. É a era da revolução digital, eletrônica e mecânica, portanto, desenvolvemos soluções cada vez mais complexas e/ou precisas para atender as especificidades dos problemas. A ascensão da indústria 4.0 e o uso de IoT dentro das empresas é um exemplo e trouxe grandes melhorias para os processos industriais.

Pensando na produção de larga escala, o transporte de produtos e materiais é uma etapa muito importante que merece atenção. 
Utilizando um robô capaz de fazer o transporte autônomo de forma inteligente, podemos obter grandes vantagens, sendo elas:

* Eficiência operacional: Carrinhos podem operar de forma contínua, sem tempo de descanso;
* Redução de custos de mão de obra: A automação do transporte elimina a necessidade de trabalhadores realizarem tarefas de transporte manual, economizando em custos de mão de obra e potencialmente reduzindo erros humanos;
* Segurança: Carrinhos autônomos são projetados com sensores avançados que podem detectar obstáculos e evitar colisões, tornando o transporte mais seguro para os funcionários e os equipamentos;
* Precisão: Esses carrinhos podem ser programados para seguir trajetórias precisas, o que é particularmente útil em ambientes industriais onde é essencial evitar danos aos produtos durante o transporte;
* Flexibilidade: Os carrinhos autônomos podem ser reprogramados ou reconfigurados rapidamente para se adaptar a mudanças nas necessidades de transporte da indústria;
* Rastreamento e monitoramento: Muitos sistemas autônomos são equipados com tecnologia de rastreamento e monitoramento, permitindo que os gerentes de operações acompanhem a localização e o estado dos carrinhos em tempo real;
* Aumento na capacidade de transporte: Carrinhos autônomos podem ser programados para trabalhar em conjunto e otimizar rotas, aumentando a capacidade de transporte da indústria;
* Redução de danos: A automação pode ajudar a reduzir danos a produtos durante o transporte, pois os carrinhos autônomos podem ser programados para evitar solavancos, choques e outros movimentos bruscos;

## 1.1 Requisitos do projeto
Mantido pelo LPAE(Laboratório de Pesquisa Avançada em Eletrônica) do IFSC(Instituto Federal de Santa Catarina), buggies em miniatura são utilizados didaticamente para professores ministrerem algumas matérias. O projeto base é mantido no repositório [**automated_buggy**](https://github.com/xtarke/automated_buggy), contendo um esquema elétrico de uma placa de potência e um de um shield que faz a adaptação dos sinais para um Arduino Uno.

Nosso projeto visa exemplificar a implementação de um sistema de transporte controlado via app android, utilizando o projeto base do buggy desenvolvido pelo LPAE. Como usaremos o microcontrolador FRDM-KL05Z, será necessário aplicar adaptações na placa shield, a fim de ajustar as tenções de sinais e de alimentação nos pinos do microcontrolador. Os seguintes requisitos de projeto foram estabelecidos:

1. Desenvolver um app android para que um smartphone possa servir de dispositivo de controle;
2. O veículo deve conseguir se comunicar com o dispositivo de controle de forma remota;
3. Monitorar e enviar o estado de sua posição atual para o dispositivo de controle.
4. Deve ter modo de operação **teleoperado**;
  > O buggy deve ser controlado manualmente através do dispositivo de controle no modo teleoperado. 
5. Deve ter modo de operação **seguidor de linha**;
  > Nesse modo, o buggy deve conseguir seguir uma tota pré-definida, seguindo uma linha preta no chão.
6. Deve ter modo de operação **piloto automático**;
  > No modo piloto automático, o buggy deve alcançar uma coordenada enviada pelo dispositivo de controle.
7. Deve desviar de objetos;
8. Monitoramento da bateria;


## 1.2 Tecnologias empregadas

* O controle do carrinho será feito utilizando um aplicativo para celular android. A comunicação entre o carrinho e o celular ocorrerá a partir do módulo bluetooth HC-05 que utiliza comunicação serial UART.

* O sistema de odometria que monitora a posição do veículo será implementado utilizando uma fusão de sensores, sendo eles: sensores de posição, encoders e uma IMU (Inertial Measurements Units) composta por giroscópio e acelerômetro.
  
* O controle manual será empregado diretamente pelo aplicativo android no celular e os comandos serão enviados via bluetooth.

* Para seguir a linha será utilizado um arranjo com dois sensores de linha, dando a possibilidade de programar o buggy para compensar a trajetória caso um dos sensores deixe de enxergar a linha.

* Será utilizado um sistema de controle PID para permitir que o carrinho se movimente até a coordenada passada de forma precisa.

* Para detectar obstáculos, serão utilizados os sensores de proximidade ultrassônicos HC-SR04, por serem acessíveis e fáceis para a aplicação.
  
* O monitoramento da bateria será feito utilizando um amplificador diferencial conectado ao ADC do microcontrolador. 

* Será necessário o desenvolvimento de um adaptador para compatibilidade do microcontrolador com a placa de potência do veículo.

* O microcontrolador utilizado será o KL05Z, requisito obrigatório para a aplicação.

## 1.3 Diagrama de blocos do projeto

A imagem abaixo exemplifica, de forma simplificada, o que foi descrito no tópico "Tecnologias Empregadas". Podemos verificar como cada periférico irá se comunicar com o microcontrolador e a comunicação com a interface para o usuário. Além do controle dos motores por meio de ponte H e a realimentação da posição a partir dos encoders. 

<p align=center> 
<strong>Figura 1 - Diagrama de Blocos do Projeto</strong>
</p>

<div align="center">


![Diagrama de Blocos](https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/Diagrama%20de%20Blocos.jpg)

</div>
