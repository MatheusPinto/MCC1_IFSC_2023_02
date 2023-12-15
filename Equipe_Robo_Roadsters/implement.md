# 3 IMPLEMENTAÇÃO
## 3.1 Hardware
Devido ao curto período disponível para implementação, a alta complexidade e a densidade do shield, o circuito se tornou a parte crítica do projeto. Inicialmente, optamos por encomendá-lo, no entanto, como o custo seria alto, fomos instruídos a fazer o shield artezanalmente. Como o circuito é dual layaer e possuí alta densidade eletrônica, recebemos apoio da equipe técnica do DAELN (Departamento Academico de Engenharia Eletrônica) para a impressão do circuito com uma CNC. Para evitar a oxidação, a placa foi ariada com palha de aço e posteriormente evernizada. Essa etapa pode ser vista na **figura 1**, juntamente com uma caneta para comparação de escala.

<p align="center"><strong>Figura 1 - Placa de circuito impresso do shield</strong></p>

<div align="center">
  
<img src="imagens/shield_placa_impressa.jpg" width="40%">

</div>

<br>

Devido à preocupação com o término do software juntamente com o atraso na obtenção da placa de circuito impresso, houve negligência com o hardware, culminando na falha do projeto. Não foi dada atenção para a dificuldade que seria soldar todos componentes devido à densidade eletrônica do circuito, e, além disso, como os furos não são metalizados, surgiu a necessidade de soldar jumpers em cada inversão de layer, além de ter que soldar todos os componentes nos dois lados da placa para que houvesse condução eletrônica. A negligência só foi percebida no último dia de prazo para entrega do projeto, assim, não foi possível entragar o shild necessário.


## 3.2 Software
O software foi constrúido abordando, primeiramente, uma metodologia top-down. Foi construído a máquina de estados, sendo a parte de mais alto nível do código, para depois a implementação dos periféricos e a integração com o código principal. A FSM, construída na main, pode ser vista clicando [**aqui**](../Equipe_Robo_Roadsters/software/main.c).<p>

Todos os periféricos implementados (motor, encoder, ultrassom e etc) foram construídos levando em consideração as regras gerais de clean code fornecidas pelo projeto de SDK do KINETIS, logo, cada periférico possuí uma pasta própria dentro da pasta "libraries", e podem ser vistos clicando [**aqui**](../Equipe_Robo_Roadsters/software/libraries). <p>

Primeiramente, o porjeto idealizou 3 modos de operação para o robô, no entanto, dada a dificultade e o curto período de tempo para desenvolvimento, as metas foram rearranjadas para implentação de apenas o modo de operação **pilo automático** ainda antes do fim do semestre letivo. Dessa forma, pensando em aplicar clean code o máximo possível, foram construídos os arquivos [**automatico.c**](../Equipe_Robo_Roadsters/software/automatico.c) e [**automatico.h**](../Equipe_Robo_Roadsters/software/automatico.h), que podem ser vistos clicando em seus respectivos nomes. Esse módulo tem o objetivo de integralizar a FSM com os arquivos de periféricos criados, permitindo que o robô funcione no modo automático de forma independente dos outros modos de opeação.<p>

Não foi possível, dentro do tempo disponível, implementar completamente o módulo de integração da FSM com os periféricos, prém, grande parte do projeto foi finalizada.

<div align="center">
  
[Retroceder](design.md) | [Pág. inicial](README.md)

</div>
