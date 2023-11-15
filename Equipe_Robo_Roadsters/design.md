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

A Máquina de estados adotada no projeto se subdivide em três modos distintos, cada qual correspondente a uma das funcionalidades do carrinho acessíveis por meio do aplicativo: modo automático, modo seguidor de linha e modo teleoperado.

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/Maquina%20de%20Estados.jpg" width="60%">

</div>

Os três modos compartilham uma fase inicial comum, na qual o carrinho é ligado e estabelece a conexão via Bluetooth. Após a conexão bem-sucedida, o sistema entra em um estado de espera designado como "Aguardando Modo de Operação". Nesse estágio, aguarda-se a recepção de um comando, codificado numericamente. Dependendo do comando recebido, o carrinho transita para um dos três modos operacionais disponíveis.

No modo automático, o carrinho permanecerá em espera até que as coordenadas do destino sejam inseridas. É importante notar que o ponto de origem (0,0) será estabelecido assim que o carrinho entrar no modo automático, e isso deve ser considerado ao escolher a coordenada de destino. Se a coordenada estiver correta e o robô não estiver no destino final (ou seja, a coordenada escolhida não é a mesma da posição atual do robô), ele avança para o próximo estado, onde realiza uma verificação dos sensores. Com a confirmação de que os sensores estão operacionais, o sistema progride para o estado "Controle PID", onde o carrinho inicia sua movimentação em direção ao destino, desviando de obstáculos conforme necessário. Após desviar de um obstáculo, o carrinho retorna à sua coordenada inicial e continua o trajeto até chegar ao destino final. Ao atingir o destino, ele retorna ao estado de "Aguardando Destino".

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/fsm_modo_automatico.jpg" width="60%">

</div>

No modo seguidor de linha, o carrinho realiza a configuração dos sensores. Se os sensores estiverem operacionais, ele entra no estado "Aguardando Comando Seguidor". Neste estado, o carro se movimenta para frente caso os sensores do lado esquerdo e direito não detectem a linha e nenhum obstáculo seja identificado. Ele se desloca para a esquerda se o sensor do lado esquerdo detectar a linha e para a direita se o sensor do lado direito a detectar. Se um obstáculo for detectado, o robô para e retorna ao estado "Aguardando Comando Seguidor". Caso o comando de retorno seja acionado, o carrinho volta ao estado inicial de "Aguardando Modo de Operação". Este comportamento permite ao carrinho navegar de forma autônoma, seguindo a linha no chão e respondendo a obstáculos de maneira apropriada.

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/fsm_modo_seguidor.jpg" width="60%">

</div>

No modo teleoperado, o carrinho realiza uma verificação dos sensores e, se estiverem em condições adequadas, entra no estado "Aguardando Comando Automático". Nesse estado, o robô é capaz de se movimentar para frente, para trás, para a direita e para a esquerda. São consideradas todas as opções possíveis que o teleoperador pode escolher, e os comandos são representados por letras na máquina de estados. No entanto, na implementação real, esses comandos são convertidos em números para facilitar o envio de sinais para o robô.

Os movimentos possíveis para o carrinho neste modo incluem acelerar para frente, acelerar para a direita, acelerar para a esquerda, ré, ré para a esquerda, ré para a direita, girar para a esquerda e girar para a direita. Importante notar que todos esses estados permitem uma transição para qualquer outro estado presente no modo teleoperado, oferecendo flexibilidade ao teleoperador para realizar transições suaves entre diferentes comandos, proporcionando um controle preciso e intuitivo sobre o carrinho.

<div align="center">
  
<img src="https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/imagens/fsm_modo_teleoperado.jpg" width="60%">


[Retroceder](https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/conceive.md) | [Avançar](https://github.com/ciceroed/MCC1_IFSC_2023_02/blob/main/Equipe_Robo_Roadsters/implement.md)

</div>
