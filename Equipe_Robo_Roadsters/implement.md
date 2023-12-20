# 3 IMPLEMENTAÇÃO
## 3.1 Hardware
O circuito do adaptador que integraria o microcontrolador com o robô se tornou a parte crítica do projeto. Inicialmente, optamos por encomendá-lo, no entanto, como o custo seria alto, foi decidido que a melhor opção seria fazê-lo artesanalmente. Como a PCI seria dupla face, recebemos apoio da equipe técnica do DAELN (Departamento Academico de Engenharia Eletrônica) que realizou a fabricação utilizando uma CNC. Para evitar a oxidação, a placa foi ariada com palha de aço e posteriormente envernizada. Essa etapa pode ser vista na **figura 1**, juntamente com uma caneta para comparação de escala.

<p align="center"><strong>Figura 1 - Placa de circuito impresso do shield</strong></p>

<div align="center">
  
<img src="imagens/shield_placa_impressa.jpg" width="40%">

</div>

<br>

Devido à preocupação com o término do software juntamente com o atraso na obtenção da placa de circuito impresso, houve negligência com o hardware. Não foi dada atenção para a dificuldade que seria soldar todos componentes devido à complexidade do circuito, e, além disso, como os furos não eram metalizados, houveram problemas na soldagem dos componentes e das vias para fazer a conexão tanto no top quanto no bottom. Assim, não foi possível terminar o circuito dentro do prazo do projeto.


## 3.2 Software
O software foi construído abordando, primeiramente, uma metodologia top-down. Iniciamos desenvolvendo a máquina de estados conforme a modelagem criada na etapa de design do projeto, dessa forma, conseguimos determinar com mais clareza as necessidades de organização das funções, pinos e periféricos que seriam utilizados. Depois passamos para a implementação dos periféricos e a integração com o código principal. A FSM, construída na [main](../Equipe_Robo_Roadsters/software/main.c), foi implementada utilizando switch case e funções para a leitura de eventos.<p>

Todos os periféricos implementados (motor, encoder, ultrassom e etc) foram construídos levando em consideração as regras gerais de clean code fornecidas pelo projeto de SDK do KINETIS, logo, foram desenvolvidas bibliotecas para cada periférico com interface para serem aplicadas em cada estado do robô.<p>

Primeiramente, o projeto idealizou 3 modos de operação para o robô, no entanto, dada a dificuldade e o curto período de tempo para desenvolvimento, as metas foram rearranjadas para implementação de apenas o modo de operação **piloto automático** ainda antes do fim do semestre letivo. Dessa forma, foram construídos os arquivos [automatico.c](../Equipe_Robo_Roadsters/software/automatico.c) e [automatico.h](../Equipe_Robo_Roadsters/software/automatico.h), onde foram desenvolvidos os eventos e funções responsáveis pela operação do carrinho para o respectivo modo de operação. 

Os eventos criados para controle da máquina de estados foram:
* IsCommandAutomatic;
* IsCommandGoBack;
* IsCoordinatesOk;
* IsOnDestination;
* Obstacles;

Também foram criadas as funções para configuração e operação dos controladores PID para a leitura das coordenadas atuais do carrinho e calculo do erro em relação às coordenadas destinos. No entanto, não foi possível desenvolver as funções do código para interpretar o erro calculado e mandar os sinais para os motores. 

Para a comunicação bluetooth com a interface criada para celulares android foi desenvolvida a biblioteca [bluetooth.h](../Equipe_Robo_Roadsters/software/libraries/bluetooth/bluetooth.h), responsável pela inicialização dos pinos para comunicação UART e também com as funções para leitura dos pinos e para envio das informações para o app.

Foi desenvolvido também uma biblioteca [ultrassound.h](../Equipe_Robo_Roadsters/software/libraries/ultrassound/ultrassound.h) para controle e leitura do sensor de obstáculos. Além disso, desenvolvemos os módulos para contole do motor, [motor.h](../Equipe_Robo_Roadsters/software/libraries/motor/motor.h) e o módulo para inicialização e leitura dos encoders das rodas, [encoder.h](../Equipe_Robo_Roadsters/software/libraries/encoder/encoder.h) .

Posteriormente foi verificado que seria necessário tratar as interrupções em um único arquivo, pois os pinos de uma porta compartilhavam o mesmo endereço de interrupção. Dessa forma, seria necessário corrigir este problema nos arquivos desenvolvidos.

Além disso, não foi possível criar em tempo hábil as funções de odometria para estimativa de posição e cálculo de distância e posição angular em relação às coordenadas de destino.

O arquivo automatico.h/.c também ficou incompleto, visto que sem todos os módulos necessários, não foi feita a integração completa dos arquivos.

Devido às dificuldades relatadas não foi possível apresentar o projeto em operação.<p>

<div align="center">
  
[Retroceder](design.md) | [Pág. inicial](README.md)

</div>
