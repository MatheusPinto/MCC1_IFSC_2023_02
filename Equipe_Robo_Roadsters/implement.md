# 3 IMPLEMENTAÇÃO
## 3.1 Hardware
## 3.2 Software
O software foi constrúido abordando, primeiramente, uma metodologia top-down. Foi construído a máquina de estados, sendo a parte de mais alto nível do código, para depois a implementação dos periféricos e a integração com o código principal. A FSM, construída na main, pode ser vista clicando [**aqui**](../Equipe_Robo_Roadsters/software/main.c).<p>

Todos os periféricos implementados (motor, encoder, ultrassom e etc) foram construídos levando em consideração as regras gerais de clean code fornecidas pelo projeto de SDK do KINETIS, logo, cada periférico possuí uma pasta própria dentro da pasta "libraries", e podem ser vistos clicando [**aqui**](../Equipe_Robo_Roadsters/software/libraries). <p>

Primeiramente, o porjeto idealizou 3 modos de operação para o robô, no entanto, dada a dificultade e o curto período de tempo para desenvolvimento, as metas foram rearranjadas para implentação de apenas o modo de operação **pilo automático** ainda antes do fim do semestre letivo. Dessa forma, pensando em aplicar clean code o máximo possível, foram construídos os arquivos [**automatico.c**](../Equipe_Robo_Roadsters/software/automatico.c) e [**automatico.h**](../Equipe_Robo_Roadsters/software/automatico.h), que podem ser vistos clicando em seus respectivos nomes. Esse módulo tem o objetivo de integralizar a FSM com os arquivos de periféricos criados, permitindo que o robô funcione no modo automático de forma independente dos outros modos de opeação.
