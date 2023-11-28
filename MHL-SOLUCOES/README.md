# CONCEIVE

O mercado de bares e pubs sempre foi uma grande procura das pessoas quando se fala em lazer, proporcionando uma experiência incrível tanto para os clientes quanto para os proprietários. Aliado a isto, existem os grandes gastos com garçons e desperdícios de produto, ocasionando uma insatisfação a todos, é válido ressaltar que a atratividade da tecnologia no bar abre vantagem contra aos concorrentes, trazendo agilidade e autonomia, reduzindo a insatisfação do cliente. Pensando nisso, a equipe MHL desenvolveu o automatizador de torneiras para chopp, trazendo a liberdade e controle ao cliente de se servir, melhorando a experiência, atratividade e confiança para quem desfruta no estabelecimento.

Neste cenário, um dos principais desafios do mercado é o desperdício. No entanto, com nossa solução em operação, essa questão passa a ser gerenciada pelo próprio usuário final. Cada mililitro retirado do sistema é cuidadosamente contabilizado e refletirá no custo final da experiência.

O controlador e medidor de mililitros automatiza o processo de servir cerveja, tornando a experiência incrivelmente simples para o usuário. Basta um único toque em um botão para liberar a cerveja em sua caneca, ao mesmo tempo em que exibe precisamente a quantidade servida na tela.

Para proporcionar uma compreensão mais clara e uma experiência de uso mais intuitiva do produto, o usuário simplesmente escolherá uma caneca de sua preferência e se dirigirá ao local onde o dispositivo está localizado. Ao chegar em frente ao equipamento, será recebido por uma tela que mostrará a quantidade de mililitros retirados atualizada em tempo real. Logo abaixo, um LED vermelho estará aceso, indicando que o fluxo está fechado, enquanto à direita, um LED verde estará apagado, ele sinalizará que o fluxo estará aberto e pronto para uso. Além disso, no centro inferior do equipamento, há dois botões que permitem ao usuário habilitar o fluxo de cerveja e se servir facilmente.

Com a caneca pronta e posicionada sob a torneira de escolha, basta pressionar o botão localizado acima da torneira. Este botão é intuitivo e facilmente identificável para o usuário. Assim que o botão é pressionado, o fluxo de líquido é iniciado automaticamente. Nesse momento, o LED vermelho se apaga e o LED verde se acende, indicando que a torneira está liberada para uso. Além disso, na parte superior do equipamento, o usuário pode acompanhar a quantidade de mililitros sendo despejada em sua caneca. Importante destacar que a tela também fornece informações sobre qual torneira está sendo utilizada para maior clareza.

Para tornar a compreensão do produto mais simples, a tela provavelmente será apresentada da seguinte maneira:

![LCD](img/LCD.jpg)


`			`Figura 3: LCD Display interface do usuário.



Dessa forma, os usuários podem facilmente identificar a quantidade de mililitros que está sendo servida na torneira.

Por último, é fascinante reconhecer a versatilidade da utilização e a variedade de implementações possíveis. Um exemplo notável é a aplicação disso em um bar, tornando a precificação da cerveja mais simples e transparente, com o cliente assumindo a responsabilidade pelo consumo e pagando apenas pela quantidade de cerveja servida. Isso não apenas melhora a experiência do cliente final, permitindo-lhes escolher a quantidade desejada, mas também destaca-se que as possibilidades são infinitas. É evidente que várias melhorias podem ser incorporadas no futuro, como a integração de sistemas de impressão digital e até mesmo o reconhecimento facial para permitir que os clientes sirvam a si mesmos.



# DESIGN - CDIO: Automatizador de Chopp

**Introdução:**

O Automatizador de Chopp representa uma solução inovadora para o mercado de bares e pubs, visando otimizar a experiência dos clientes e a eficiência operacional dos estabelecimentos. Este design conceitual aborda os principais aspectos físicos, eletrônicos e de interface do usuário para garantir a eficácia e a atratividade do produto.

Diagramas de Blocos:

![diagrama](img/diagrama.png)


`			`Figura 2-  Diagrama de Blocos.

Sistema Eletrônico:

![esquematico](img/esquematico.png)


`			`Figura 2-  Fluxograma de Operação.


Conforme o fluxograma acima, o start do sistema é dado quando o cliente coloca a caneca de Chopp e pressiona o botão para iniciar. Após apertar o botão da torneira desejada, a placa recebe o comando e libera a saída programada para acionar o relé, que por sua vez irá liberar o solenóide de fluxo unilateral que irá liberar a passagem do chopp. Em sequência, o CHOPP passa pelo contador de fluxo que a cada giro das pás gera um pulso que está em referência de um ímã, enviando um sinal PWM, que por sua vez será lido pela placa e apresentado no display a quantidade de ML em tempo real. Por fim, basta degustar do CHOPP selecionado!


### Interface do Usuário:

1\. Tela de Exibição:

- Localizada na parte frontal do equipamento, uma tela LCD ou LED exibirá informações como a quantidade de mililitros sendo servida e a torneira selecionada.

2\. LEDs de Indicação:

- Dois LEDs (um vermelho e outro verde) para cada torneira estarão posicionados abaixo da tela para indicar o status do fluxo de cerveja: vermelho para fechado e verde para aberto.

3\. Botões de Controle:

- Dois botões de controle estarão dispostos abaixo dos LED’s para permitir que o usuário selecione a torneira desejada e habilite o fluxo de cerveja.

4\. Local para extração do Chopp:

- As torneiras automatizadas estarão dispostas na parte inferior do equipamento, posicionadas de forma que o fluxo de cerveja seja direcionado para a caneca de maneira controlada.

5\. Design de Interface de Usuário:

- A tela exibirá claramente as opções de torneiras e a quantidade de mililitros a ser servida em cada torneira;
- O layout será intuitivo e fácil de entender, permitindo uma navegação suave para o usuário.

6\. Design Estético:

- Cores atraentes e apropriadas para o ambiente de bar, como o preto do Gabinete e iluminação de LED para dar um visual atraente e sofisticado ao equipamento.

![interface](img/LCD.jpg)


`			`Figura 3: LCD Display interface do usuário.




Segue figura 4 exemplificando o produto final pela visão do usuário:

![Interface](img/Interface.png)


`			`Figura 4: Interface final do Usuário.


**Conclusão:**

O design do Automatizador de Chopp busca unir a funcionalidade técnica com uma estética atraente, oferecendo um produto que atenda às necessidades dos clientes e dos estabelecimentos comerciais. Com uma abordagem centrada no usuário e aprimoramentos contínuos baseados em feedbacks, buscamos oferecer uma solução de alta qualidade que revolucione o cenário dos bares e pubs, tornando a experiência de servir e desfrutar de um chopp mais eficiente e prazeroso.