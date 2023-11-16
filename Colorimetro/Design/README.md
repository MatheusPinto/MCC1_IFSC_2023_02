
**DESIGN**

Nosso projeto será um colorímetro, um equipamento que irá fazer a analise de determinadas substancias presentes na água.

Para poder fazer essas analises utilizaremos alguns periféricos do microcontrolador MKL05Z36, que são:

  

-   Conversor ADC
    
-   Comunicação I2C
    
-   GPIO
    
-   Timer
    

  

Além dos periféricos do microcontrolador utilizaremos também:

  

-   Poço escuro
    
-   Botões push button
    
-   LED RGB
    
-   LDR
    
-   Controle de corrente dos LEDs
    
-   Display LCD 16x2
    
-   CI AD8544 (AmpOp)
    
-   CI 24C256 (Memória)
    

  

**Conversor ADC**

  

Para utilizar o conversor ADC do microcontrolador utilizaremos o CI AD8544, ele irá receber o sinal do sensor LDR, que é um sinal analógico, em convertê-lo em um sinal digital para que o microcontrolador possa fazer os cálculos e mostrar o resultado na display.

  
![](https://lh7-us.googleusercontent.com/3v7vyvyseopTssvUGKUnno0HKRafrsa-zJ6AG-2lmyaM0j62mrNksGuHQgqiLiXng9Xgnph7MDCRG7z61DSssDuVmhetFAbaqZ755gPspeZvDeGD5dsVUesc5pMdgFzQOraIA761mNG88wDTQe_vABHJaWqDBjri)  
  

Os resistores estão polarizando o AmpOp para que ele funcione em modo de subtrator, onde ele ira subtrair as duas tensões de entrada e mandar essa diferença para a saída dele. O capacitor esta servindo como um filtro, para que ele tenha um resulto com a menor quantidade de ruido possível.

  
![](https://lh7-us.googleusercontent.com/KLCiPVgx6qk1oFbxVbz7eaLA5MVB9TjC22mDsklSUXFtgiIIidHWwuejmlBEHBXupudm3lk8IzOmGDLPc-jv8FgFa7v6ZTiSlBzO5DG_wL6SJKbK9XS5dwgPWMB1xOj7dj6iKRGbONcgoq5iyGLbFrdr0wrrI36f)  
    


**Comunicação I2C.**

  

A comunicação I2C será utilizada para fazer a comunicação entra a memória (CI 24C256) e o microcontrolador, para escrever na memória e ler da memória.

  
![](https://lh7-us.googleusercontent.com/TuF_bCrhndw7SfGBfVTCBz_PKwH_mfaTHq2Z5YjaVJoG105-DY11eyz6pPPkSR2dNGD18BHaTK9wAYOP-hIXVcD1p3bK-PmbRc1WfHUbDCj1K6FSe6xvWkTbyRqpMKLG92WPr16b0Di7swtSIDDEAQoPnagnzsOi)  


Será utilizado 2 resistores de 2.2K Ω para fazer o pull up para que ele funcione em uma frequência de 50KHz, dessa forma não utilizaremos o pull up interno do microcontrolador.

  

**GPIO.**



O periférico de GPIO será utilizado para fazermos o acionamento do display e para receber os comandos vindos do teclado, definindo os pinos estão conectados os terminais do display como saída, para que ele possa escrever no display e os pinos onde estão conectados os botões serão definidos como entrada, pois o microcontrolador ira receber o sinal vindo dos botões para saber qual botão foi precionado.

  
  

**Timer.**

  

O timer será utilizado para fazer o controle da intensidade de luz dos LEDs através do PWM, alterando o duty cicle do sinal de PWM para aumentar ou diminuir a intensidade do LED, o controle desse PWM será manual, fazendo com que quem estiver manuseando o equipamento possa ter o controle da intensidade do LED, ajustando ela para o valor que ele quiser.

  

**Poço escuro.**

  

O poço é onde iremos inserir a amostra de água para que possamos fazer a analise,nele haverá um vão no meio para que poço ser inserido uma cubeta de vidro com a amostra dentro, e nas laterais do poço estará o LED RGB e o sensor LDR, os dois em 180° em relação ao outro, ou seja, um de frente com o outro.

  
![](https://lh7-us.googleusercontent.com/89eikSVvDLMsBMFs83y6CuYLC-ktDvBtelnKzzGYHJh9-JRVjizGjKLBAv_P5VUB3KUkFUJ83PvDcs6wY1lzSxtExogE3y9ymiHuW4i1EdA2Y4Y2t8Mb5Pz2ST0pxz-vSL5UeEVbY6QhiAfIccrz_DhFbqBgSXi9)  
  
 Na imagem observamos que o LED esta de frente para o sensor LDR, a luz que sai do LED esta diretamente indo para o sensor com uma certa intensidade de luz.

 
  
![](https://lh7-us.googleusercontent.com/B7zd_JqD5sqGrR04zgNNYJJiZ_N4T2jZfJcZ1F0CyilZAbdIFTPc8IDXT15nhrPo0TmUjS14Nb3aOh1-wZ-rmR0BQJ3elyQ66P4lo289acwAgRFO3XIQi8PhEsLU2kzPNLxMJqkJOx2jyDiCvwPFamgVLhYxrk3v)  
  
 
Na imagem acima podemos ver como é que ficara o poço com a cubeta dentro dele, a luz do LED passara por essa cubeta até chegar ao sensor, dependendo da amostra que estiver dentro da cubeta essa luz ira sofrer com perdas de luminosidade, essa diferença de luz de uma amostra para a outra que será utilizada utilizada para fazer os caculos para chegarmos no resultados.

  
   
![](https://lh7-us.googleusercontent.com/sUr8jt3HzhkfmqZ63tcL95iWpdW0sR6gVcfhxkfXxv7ZgpOmP-K8wye54O-DtjPrhnwxl3t2-lAuKydaEG-8ILvj6Va4Xnwfv1mbPlmQjk1ICgYtK4MP65ddebHoz1KJ7MysHctrW2jU9s6nvxDlxxc0px03xe_9)  
  

Como podemos ver na imagem o poço terá uma tampa, essa tampa servira para que não entre luz externa para dentro do poço, fazendo com que a luz externa não interfira nos resultados das leitura. O LED e o LDR também serão vedados com uma fita isolante liquida preta, fazendo com que também não entre luz externa por eles para dentro do poço.

  

**LED RGB e LDR.**
  

Para fazermos as leituras utilizaremos um LED RGB como o emissor do sinal e um sensor LDR como o receptor de sinal
 
  
![](https://lh7-us.googleusercontent.com/_RJ4_6PsGR7qVB2Kdvux0Q02Vpevp-MtyFXmchfe1u5FLw5rVGi78lMa8F6LvPtXtuATktnHwIczU5OKTOKwRaH4clNiVeyI8PQyh3Imv4LdKoX4VdIru1Xw1WgZggHxB6R5yWBbwb9jPssKtR4yIzTVRb0U2UkJ)![](https://lh7-us.googleusercontent.com/IFtZwUeIo0ay0v3YErpm7L-nf4Lvqk-0KU7QqgiZ7qIBEXnBhdP-pkkB9cBkY287_Uyf3brVk0dh21VBeHMg65_j891pwtB7Ajh1UUtB-S6zQXRBtN4uuVQZ2OHUtG9ZFjQUR3tFOMdwPKkxOGjAU7ZD2R1FCw4C)  
  
  

O LED RGB será um LED com três cores, que serão a cor verde, azul e vermelho, sendo acionada somente uma delas para fazer as leituras, a seleção da cor do LED será feito por quem estiver manuseando o equipamento, pois cada reagende (amostra da água com a reação) será necessário utilizar uma cor especifica do LED, exemplo, se formos analisarmos a quantidade de cloro na aguá teremos que utilizar o LED verde para fazer essa analise.

O sensor LDR será utilizado um sensor cuja a resistência máxima que ele pode atingir é de 10K Ω, todo o circuito responsável pelas leituras será dimensionado para um LDR com resistência máxima de 10K Ω

  

**Botões push button.**

  

Os botões push button serão utilizados para navegar nos menus do equipamento, como por exemplo para selecionar a com do LED que será medida, ou para ajustar o PWM do LED, para mandar medir, etc…

![](https://lh7-us.googleusercontent.com/ciMtbUEcVoI5Kfgtu5lB6pzgbVWs1wdAwtdWEtSOxVBJQaTfIUefLufdtJ6Fu4eGaUFtTJB_jbD4mT79fhgNHpyLQjR31pRgs0ACqT-vn_b8XZdxolYHopY51Y27AksYcz_wTFDYizPcItrMbPQ04e72gZNcsQQ1)

  

**Botões push button.**
  

Ao todo serão utilizados 4 botões, sendo um que o botão de cima da imagem será o “CIMA”, o botão de baixo será o “BAIXO”, o botão da direita será o de “OK”, e da esquerda o “BACK”, os botões irão funcionar através de pulling e não por interrupção, onde no firmware será testado se o botão foi pressionado ou não, retornando 0 ou 1.

  

**Display LCD 16x2.**

  

Para exibir as informações em um visor utilizaremos um display LCD 16x2, a comunicação do microcontrolador com o display será feita através do periférico GPIO do microcontrolador, onde os terminais do microcontrolador conectados no display serão definidos como saída, pois mandarão o sinal para o display.

  
![](https://lh7-us.googleusercontent.com/zszt5sIouuaWG3zQ8zu7OIk47MGwdygC88rfJTTwnsJCaVKLWwoCBznjoEYCewBcMMgnPekRpH8Cnp9NmMDTV3HhJRcm8qRQvcdME8-uCyTxerI3CWzigxxdx-JwjtuK22C08P6MuVl_nboOVu8Xvg6-tb3fQ3pK)  
  
**Controle de corrente dos LEDs.**

  

Será utilizado um driver de corrente para limitar a corrente dos LEDs, ele é composto por uma rede resistores simples só para fazer a limitação das correntes, onde cada resistor estará conectado a um LED para limitar a corrente dele.

  
![](https://lh7-us.googleusercontent.com/xjXocYzNW633nnOkx85EVvE-r_I_P4-uD4535qXV7cU5qnQm5KWqqcT1VGFz1fkloqa2n6_-Lni_JR_n-RKZBVNg-0OZs8I3hBRm-JIxNXuwMGtYXi1Q0coY5ACVNlElsAGO-vUE7vUB89ghGNCav4HJAexCx937)  
  
  
No LED vermelho esta ligado um resistor de 3.3K Ω, no LED verde esta ligado um resistor de 15K e no LED azul esta ligado um resistor de 2.7K Ω.

  

**Protótipo para testes.**

  

Ainda não temos uma placa montada ou um layout já pronto do circuito, temos só um protótipo para que possamos realizar alguns testes, para ver se o código esta funcionando corretamente, ver se esta havendo variação nas leituras do LED, se as frases do display estão corretas, etc…

  
![](https://lh7-us.googleusercontent.com/AnTetF3RfFUIv6xg9NBODl_KgXj9FsYWYFuwwdfGax6TDMBggkkWyLd6RJgAuLv3B3r2MtiO4CNl64jO1Rp1kDyUtp61nEfGgmq0CVuhGAQEMgXJUz4X1Kw1jsZ-ACAIh_TZwGmrIHWLIOOPHWGsfoGmrFNMiNIy)  
  
  
