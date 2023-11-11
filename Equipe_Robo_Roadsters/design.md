# 2. DESING DO PROJETO

## 2.1   Hardware

## 2.2   Software

Para o Software, foi desenvolvido uma máquina de estados levando em consideração os requisitos de projeto e um app para servir de interface entre o usuário e qualquer RoboRoadster.

### 2.2.2 App de interface humana

O app RoboRoadster foi criado a partir do [**MIT app inventor**](https://ai2.appinventor.mit.edu/), um site com ambiente de desenvolvimento de aplicativos Android e IOS que permite criar apps com programação em blocos. O app permite escolher o RoboRoadster disponível para conectar-se via bluetooth e, posteriormente, escolher o modo de operação seguidor de linha, automático ou teleoperado. O microcontrolador fornece as coordenadas atuais do carrinho para o app, que mostra na 3 telas de modo de operação. <br>
A tela inicial do app é mostrada na **Figura 2** abaixo.

<p align="center"><strong>Figura 2 - Tela inicial do app</strong></p>

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/tela_inicial_app.png" width="40%">

</div>

<br>

Assim que escolhido um RoboRoadster para conectar-se, uma mensagem de "bluetooth conectado" surge e as opções de modo de operação são desbloqueadas. Observe na **Figura 3** e **4** o processo descrito. <br>

<p align="center"><strong>Figura 3 - Tela de escolha do Roboroadster</strong></p>

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/tela_escolha_dispositivo.png" width="40%">

</div>

<br> <br>



<p align="center"><strong>Figura 4 - Tela de escolha do modo de operação</strong></p>

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/tela_escolha_modo.png" width="40%">

</div>

<br>

No modo automatico, o usuário entra com as coordenadas x,y de destino do RoboRoadster, em metros, que é repassada via bluetooth para o microcontrolador. Veja a tela descrita na **Figura 5.** <br> 

<p align="center"><strong>Figura 5 - Tela de modo automatico</strong></p>

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/tela_automatico_app.png" width="40%">

</div>

<br>

No modo seguidor de linha, o Roboroadster apenas segue uma linha, conforme o comando do usuário para iniciar a operação. O comando é enviado ao microcontrolador após o usuário tocar no mapa da tela mostrada na **Figura 6.** <br>

<p align="center"><strong>Figura 6 - Tela de seguidor de linha</strong></p>

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/modoSeguidor.png" width="40%">

</div>
<br>

Por fim, o modo teleoperado deixa o usuário controlar o robo através de comandos de direções. Cada comando de direção tocado na tela envia um valor diferente para o microcontrolador, que interpreta como comando para qual direção que o RoboRoadster deve seguir. Tocando a seta "para cima" ou "para baixo", o robo deve seguir em frente ou para trás, respectivamente. Já as setas laterais indicam para qual lado o rodo deve girar, e as combinações das setas são interpretadas como curvas a serem feitas. Veja na **Figura 7** a tela do modo teleoperado. <br>

<p align="center"><strong>Figura 7 - Tela de modo teleoperado</strong></p>

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/modoTeleoperado.png" width="40%">

</div>

<br>

### 2.2.1   Máquina de estados


















<div align="center">

[Retroceder](https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/conceive.md) | [Avançar](https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/implement.md)

</div>
