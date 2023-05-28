# Busca em Profundidade (DFS), Largura (BFS) e Randômico

<div style="display: inline-block;">    
<img align="center" height="20px" width="20px" src="https://img.shields.io/badge/-C-blue"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>

<p> </p>
<p> </p>

<p align="justify">
Alunos: José Marconi de Almeida Júnior, Lucas Fernandes Barbosa de Andrade.

<p align="justify">
O trabalho se trata de percorrer uma matriz quadrática lida de um arquivo em busca de um determinado ponto de parada. Ela deve ser percorrida usando 3 tipos diferentes de busca: Randomicamente, lógica essa já implementada no trabalho anterior, busca em Profundidade(DFS) e em Largura(BFS). A matriz sera composta pelos seguintes caracteres:

|          Caractere            | Função                                                                                                                                                    |
| ------------------------------| --------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `#`                          | Parede, o <i>player</i> não pode andar para as posições com esse caractere.                                                                               |
|  `*`                          | Perigo, quando adentrar a uma casa com esse caractere, o caminhamento é resetado para a posição inicial nas 3 formas sendo iniciado novamente totalmente do zero e o caractere é trocado para `1`.                                                                                                                                                                                        |
|  `1`                          | São as casas que podem ser percorridas normalmente.                                                                                                       |
|  `?`                          | Ponto de parada, quando o <i>player</i> cair nessa casa, ele sai da matriz e o programa encerra.                                                                                                                                                      |

<p align="justify">
A matriz utilizada será a mesma para as 3 formas diferentes de busca e seus caracteres devem ser alocados de maneira totalmente aleatória. Além do mais, é necessário uma comparação entre os 3 algoritimos de caminhamento, mostrando o número de passos dados e tempo de execução para finalização da busca.  

<p align="justify">

<p> </p>

<p> </p>


# Arquivos e Funções
<p align="justify">
O código é dividido em 7 arquivos, sendo eles:

|  Arquivo                        |   Função                                                                                          |
| ------------------------------- | ------------------------------------------------------------------------------------------------- |
|  `main.c`                       | Arquivo principal para iniciar o algoritimo.                                                      |
|  `lab.h`                        | Define as funções de busca e de leitura de arquivo do programa.         |
|  `lab.c`                        | Contém as funções responsáveis pelos métodos de busca, além de conter a função que realiza a leitura da matriz do arquivo                                               |
|  `queue.h`                      | Define as funções para se trabalhar com a fila.                                                   |
|  `queue.c`                      | Formatação das funções declaradas na queue.h.                                                     |
|  `stack.h`                      | Define as funções para se trabalhar com a pilha.                                                  |
|  `stack.c`                      | Formatação das funções declaradas na stack.h                                                      |

<p align="justify">
As funções mais importantes utilizadas são:

|  Função                                                       |  Funcionalidade                                                                                   |
| ------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
|  `LerMatriz` - [`lab.c`, linhas 6 a 74]                       | Realiza a leitura do arquivo, salvando a matriz utilizada e chamando as funções de caminhamento;  |
|  `Caminho` - [`lab.c`, linhas 76 a 223]                       | Realiza a busca de forma Randomica;                                                                 |
|  `DFS` - [`lab.c`, linhas 225 a 312]                          | Realiza a busca em Profundidade;                                                           |
|  `BFS` - [`lab.c`, linhas 335 a 994]                          | Realiza a busca em Largura;                                                                |

<p align="justify">
As funções utilizadas dos arquivos <i>queue.h<i>/<i>stack.h<i> e <i>queue.c<i>/<i>stack.c<i> são responsáveis pela inserção e remoção de componentes na fila e na pilha. Além de conter funções auxiliares que facilitam o desenvolvimento da lógica do programa.

<p> </p>

<p> </p>

# Fila (queue) e Pilha (stack)

<p align="justify">
A fila e a pilha foram utilizadas nas buscas em largura e em profundidade respectivamente. Suas funções serão especificadas ao longo da explicação das logicas de busca.

<p align="justify">
Mas segue um quadro para explicar rapidamente como funcionam as funções implementadas relacionadas a fila e a pilha:

|  Função                         |   Funcionalidade                                                                                  |
| ------------------------------- | ------------------------------------------------------------------------------------------------- |
|  `FFvzia` e `FPvzia`            | Utilizadas para inicializar a fila e pilha e alocar os ponteiros no topo e na base.                   |
|  `isVaziaQueue` e `isVaziaStack`| Retorna um booleano como true, caso a fila ou pilha esteja vazia.                                 |
|  `Enfileira` e `Push`           | Salva os valores na fila e na pilha.                                                              |
|  `Desenfileira` e `Pop`         | No caso da fila, retira o primeiro elemento e da pilha retira o último elemento                   |
|  `Fimprime` e `Pimprime`        | Retorna na tela toda a fila ou pilha.                                                             |

<p> </p>

<p> </p>

# Lógicas Implementada

|  Posições possíveis de caminhar                                                                   |
| ------------------------------------------------------------------------------------------------- |
| Direita (Leste);                                                                                  |
| Esquerda (Oeste);                                                                                 |
| Cima (Norte);                                                                                     |
| Baixo (Sul)                                                                                       |
| Diagonal de Cima a Direita (Nordeste)                                                             |
| Diagonal de Cima a Esquerda (Noroeste)                                                            |
| Diagonal de Baixo a Direita (Sudeste)                                                             |
| Diagonal de Baixo a Esquerda (Sudoeste)                                                           |       

# Random
<p align="justify">
A função responsável pela busca randômica é a função Caminho(), a lógica usada para desenvolve-la foi basicamente a mesma usada no trabalho do Labirinto Recorrente. Durante a trajetoria dependendo da posição atual são gerado numeros entre -1 e 1 usando a função rand() para as variaveis path_linha e path_coluna. Esses valores gerados são incrementados nas variaveis posicao_linha e posicao_coluna e realizando o caminho, por exemplo, se a posição atual for posicao_linha = 2 e posicao_coluna = 1, e for gerado 0 e 1 nas variaveis path_linha e path_coluna, a posição nova será posicao_linha = 2 e posicao_coluna = 2, ou seja ele caminhou para direita. Existem casos em que não se pode gerar números nesse intervalo, por exemplo se a posição atual for na primeira linha, não pode gerar -1 na variável path_linha, já que não existe uma linha a cima da primeira, nesses casos existem tratamentos únicos para cada caso em particular.

<p align="justify">
O função irá executar até encontrar o caractere "?", caso não for encontrado o programa irá parar e mostrar que não é possível encontra-lo. Além disso como foi dito, caso o algoritmo se depare com o caractere "*", ele irá retornar para a posição inicial e a posiçao que era "*" irá passar a ser "1". Em casos onde o ponto de parada não pode ser encontrado é usado um contador de casas percorridas que contém o caractere "0" e um contador de casas percorridas que contém o caractere "1", caso o numero de casas contendo "0" for igual ao número de casas contendo "1" vezes o tamanho da matriz ao quadrado, o programa se encerra. Fazendo isso o algorítmo irá ficar rodando por um bom tempo, essa condição irá assegurar que o programa percorreu todas as casas válidas, caso encontre o ponto de parada, o programa para, caso cotrário só irá parar qundo o número de casas percorridas contendo "0" for tão grande a ponto dele ter caminhado em todas as posições válidas.

<p align="justify">
De qualquer maneira ao final é mostrado no terminal o resultado da matriz com as casas visitadas, o tempo de execução e a quantidade total de passos.

<p align="justify">
Exemplo de saída da busca Randômica:
 
<p align="center">
<img height="600px" width="600px" src="imagens/SaidaRandom.png"/>
<p> </p>

# DFS
<p align="justify">
A busca em profundidade é um algoritmo utilizado para percorrer ou buscar itens dentro das estruturas de dados grafos, árvores ou em matrizes como foi o caso desse trabalho. Existem várias formas de implementar uma busca em profundidade, no caso deste trabalho foi utilizado um algoritmo iterativo e utilizando uma pilha (LIFO) para controlar as casas a serem visitadas.

<p align="justify">
A lógica utilizada para realizar a busca em profundidade neste trabalho foi relativamente simples, usando apenas duas funções principais, sendo elas, DFS() e Empilhar(). A função DFS() é realizado a parte central da lógica, já a função Empilhar() serve apenas para empilhar elementos na pilha que irá controlar todo o processo de busca. A função DFS() contém um loop no qual irá ocorrer todo o processo de busca. Antes de entrar no loop, a posição que é representada por duas variaveis sendo elas, posição_linha e posição coluna são setadas como 0 cada uma, já que a posição inicial sempre será a posição 0x0 da matriz. Após isso com a função Push(), a posição incial é colocada no topo da pilha. Dentro do loop a primeira coisa a ser feita é igualar a posição atual à posição que está no topo da pilha, no caso de ser a primeira iteração a posição atual será a incial, já que antes de entrar no loop a posição inicial foi setada no topo da pilha. Após isso o topo da pilha é removido com a fuunção Pop(), para poder empilhar as posições vizinhas. Ainda dentro do loop é feito uma verificação para ver se a posição atual é "*", caso for o proograma irá limpar toda a pilha para poder recomeçar a busca. Porém caso a posição for "1", o programa irá marcar a posição atual como '0" para mostrar que essa posição já foi acessada, e irá começar a empilhar as posições vizinhas validas para caminhar, posições essas que serão marcadas com "x" para mostrar que foram empilhadas. A ordem que o programa empilha as posições vizinhas foi escolhida por nós, sendo assim, a última posição empilhada é a direção que tem prioridade na busca, já que no começo do loop a posição atual sempre sera igualada ao topo da pilha. Este processo irá se repetir até ser encontrado o ponto de parada, caso não seja possível alcançar este ponto, a pilha ficará vazia já que o programa só empilha casas não visitadas. Dessa forma chegará um ponto que não será empilhado mais nada e sempre que retorna o início do loop o programa remove o topo da pilha como já mencionado. Assim a condição do while será satisfeita e o programa sairá do loop, condição essa que estabelece que o loop irá rodar até a função isVaziaStack() retornar true, o que significa que a pilha está vazia. Está função retorna true quando o ponteiro do topo for igual ao ponteiro da base da pilha, indicando a pilha está vazia. Quando o ponto de parada é achado, uma variável do tipo bool chamada vitória, retorna true, sinalizando que o ponto foi achado, caso o programa saia do loop e essa variável se mantém false (já que no início ela foi setada como false), será mostrado que foi impossível achar o ponto.

<p align="center">
<img height="600px" width="600px" src="imagens/DFS.png"/>
<p> </p>

<p align="justify">
A figura acima demonstra a lógica de uma busca em profundidade

<p align="justify">
Exemplo de saída do método do DFS: 

<p align="center">
<img height="600px" width="600px" src="imagens/SaidaDFS.png"/>
<p> </p>

# BFS
<p align="justify">
A busca em largura é um algoritmo utilizado para percorrer ou buscar itens dentro das estruturas de dados grafos, árvores ou assim como a busca em profundidade, em matrizes. A busca em largura pode ser implementada de várias formas. As mais utilizadas são através de recursão, que utiliza pilha (LIFO), ou iterativamente, através de uma fila (FIFO), que será o caso desse trabalho.
 
A lógica implementada na buca em largura (BFS), foi utilizando uma espécie de "radar". 

<p align="justify">
O <i>player<i> inicia sempre na posição <i>[0][0]<i> da matriz (que sempre será <i>1<i>), a partir dela, primeiro é verificado o raio do local onde ele está. Averiguando todas as posições possíveis para caminhar, levando sempre em consideração o raio da matriz, e mudando o caractere delas para <i>x<i>, mas somente se o caractere da posição for <i>1<i>, se for <i>*<i> ou <i>?<i> o caractere não trocado. Dessa forma, ele salva todas essas posições que ele pode caminhar, que são as posições diferentes de <i>#<i>, <i>x<i> e <i>0<i>. Elas são salvas em uma fila, que é utilizada para caminhar. 

<p align="justify">
Ele sempre caminhará para a primeira coordenada da fila, e o caractere da posição será trocado para <i>0<i>. No momento que isso acontece, essa coordenada já utilizada é retirada da fila, e então utilizará novamente o radar para salvar novas posições para a fila e em seguida caminhará para a posição seguinte que estiver salva.

<p align="justify">
Caso o <i>player<i> caia em uma posição com o caractere <i>*<i>, o caractere será trocado para <i>1<i>, e o <i>player<i> voltara para a posição inicial da matriz(<i>[0][0]<i>), e a matriz até então modificada, é resetada para como estava anteriormente, porém com a nova mudança de caractere. Dessa forma, sempre que o player cair no perigo, ele recomeça o caminho e aquele perigo é retirado. A fila também é sempre limpa nesse momento, começando a salvar as posições desde o inicio novamente.

<p align="justify">
A condição de vitória do <i>player<i> é caso ele consiga cair na casa com o caractere <i>?<i>. Logo após isso, é imprimida na tela a matriz modificada, o tempo de execução e o número de passos totais que ele deu para conseguir vencer. Os passos do personagem não são resetados quando ele cair nos perigos. Há ainda a condição de parada, caso ele não encontre a <i>?<i>, o algoritimo para assim que a fila estiver vazia, logo, até ele percorrer todas as posições possiveis na matriz.

<p align="justify">
Exemplo em imagens do comportamento do <i>player<i> e a utilização do "radar":

  </div>
  </div>
  </div>
 
<div style="display: inline_block"><br>
  
  <img align="center" height="400px" width="400px" src="imagens/Ex1.png"/>    
  <img align="center" height="400px" width="400px" src="imagens/Ex2.png"/>    
  <img align="center" height="400px" width="400px" src="imagens/Ex3.png"/>

</a>
</div>

<p> </p>

<p> </p>

<p align="justify">
Exemplo de saída do BFS:

<p align="center">
<img height="600px" width="600px" src="imagens/Exsaida1.png"/>

<p> </p>

<p> </p>

# Testes Realizados

<p align="justify">
Os testes foram feitos rodando o programa 10 vezes, guardando os valores dos passos e do tempo que foram necessários, e tirado a médias dos valores. Detalhe que, no programa o tempo de execução é retornado em segundos, porém, para os resultados finais, para uma melhor visualização, os valores foram transformados para milissegundos.

<p align="justify">
A primeira bateria de testes foi realizado na seguinte matriz:

<p align="center">
<img height="600px" width="600px" src="imagens/ExTeste1.png"/>

É uma matriz que em que não é possível chegar ao <i>?<i>, logo, de certa forma, eles caminham por toda a matriz até um critério de parada. Nesta matriz, até os critérios de parada conseguimos os seguintes valores:

|  Modo de percorrer              | Média do tempo de execução(ms)| Média de passos totais dados          |
| ------------------------------- | ----------------------------- | ------------------------------------- |
|  `Randomico`                    |            236859             |            6541119                    |
|  `DFS`                          |             53093             |             488585                    |
|  `BFS`                          |             52098             |             656450                    |

<p> </p>

<p> </p>

<p align="justify">
A segunda bateria de testes foi realizado na seguinte matriz:

<p align="center">
<img height="600px" width="600px" src="imagens/ExTeste2.png"/>

É uma matriz que em que é possível chegar ao <i>?<i>, e se encontra na última posição da matriz([49][49]):

|  Modo de percorrer              | Média do tempo de execução(ms)| Média de passos totais dados          |
| ------------------------------- | ----------------------------- | ------------------------------------- |
|  `Randomico`                    |             62733             |            1663778                    |
|  `DFS`                          |              2158             |                968                    |
|  `BFS`                          |             53528             |             659041                    |

<p> </p>

<p> </p>

<p align="justify">
A terceira bateria de testes foi realizado na seguinte matriz:

<p align="center">
<img height="600px" width="600px" src="imagens/ExTeste3.png"/>

É uma matriz que em que é possível chegar ao <i>?<i>, e se encontra na posição <i>[0][49]<i>:

|  Modo de percorrer              | Média do tempo de execução(ms)| Média de passos totais dados          |
| ------------------------------- | ----------------------------- | ------------------------------------- |
|  `Randomico`                    |             17117             |             435265                    |
|  `DFS`                          |              6247             |              27679                    |
|  `BFS`                          |             46142             |             538837                    |

<p> </p>

<p> </p>

<p align="justify">
A quarta bateria de testes foi realizado na seguinte matriz:

<p align="center">
<img height="600px" width="600px" src="imagens/ExTeste4.png"/>

É uma matriz que em que é possível chegar ao <i>?<i>, e se encontra na posição <i>[49][0]<i>:

|  Modo de percorrer              | Média do tempo de execução(ms)| Média de passos totais dados          |
| ------------------------------- | ----------------------------- | ------------------------------------- |
|  `Randomico`                    |             39381             |            1043907                    |
|  `DFS`                          |             25768             |             203230                    |
|  `BFS`                          |             53260             |             636736                    |

<p> </p>

<p> </p>

<p align="justify">
A quinta bateria de testes foi realizado na seguinte matriz:

<p align="center">
<img height="600px" width="600px" src="imagens/ExTeste5.png"/>

É uma matriz que em que é possível chegar ao <i>?<i>, e se encontra na posição <i>[5][7]<i>:

|  Modo de percorrer              | Média do tempo de execução(ms)| Média de passos totais dados          |
| ------------------------------- | ----------------------------- | ------------------------------------- |
|  `Randomico`                    |              3848             |              70338                    |
|  `DFS`                          |             24051             |             178565                    |
|  `BFS`                          |              4764             |              24764                    |

<p> </p>

<p> </p>

# Análise dos Testes

<p align="justify">

Levando em consideração o primeiro exemplo mostrado de uma matriz sem ponto de chegada, apesar de menos passos dados, o DFS é ainda mais lento em tempo de execução que o BFS. Enquanto o Randomico é necessário um certo critério de parada que pode deixa-ló mais lento que os demais.


<p align="justify">

No segundo exemplo temos que o ponto de chegada se encontra na última posição da matriz. Nesse caso, o DFS foi infinitamento superior que ambos BFS e Randomico, tanto em tempo de execução quanto em quantidade de passos. Entre BFS e Randômico, o tempo de execução foi por uma diferença de 10000ms (dez mil milissegundos), uma diferença relativamente pequena, levando em consideração que o Randômico contém uma média de passos quase duas vezes maior que o BFS.

<p align="justify">

Na terceira matriz temos o ponto de chegada no topo da matriz e na sua última coluna. Mais um caso em que o DFS supera e muito os outros dois casos com um tempo de execução ainda bem menor que a metade do tempo de execução do segundo melhor que nesse caso foi o Randômico, mas, em relação aos passos dados, DFS teve um aumento consideável com relação ao teste anterior. Esse é um caso em que o BFS se desempenhou relativamente mal para encontrar o ponto de chegada mas teve uma performance melhor que o caso anterior tanto em tempo de execução quanto em passos. Enquanto o randômico se performou extremamente bem em comparação ao caso anterior.

<p align="justify">

A quarta matriz contém o ponto de chegada na última linha e na primeira coluna. E é mais um caso em que o DFS performou melhor que os demais, porém com um aumento significativo tanto de tempo de execução quanto em número de passos, batendo seus maiores valores até então, com excessão da primeira utilizada para mostrar o caso em que não há ponto de chegada. BFS nesse caso foi bem parecido com o caso de teste 2 em seus valores, e novamente foi o maior em tempo de execução mesmo com menos passos que o Randômico, que novamente excedeu os 1000000(1 milhão) de passos. 

<p align="justify">

O caso de teste 5 contém um ponto de chegada mais próximo da posição de inicio, porém está envolta de paredes, tendo sua única entrada sendo por baixo. Nesse caso, DFS foi de longe o pior tanto em tempo de execução quanto em passos, porém se comparar com os valores dos testes anteriores, mesmo sendo um caso espécifico e que ele perde em muito, os valores são relativamente baixos. Com relação ao BFS, novamente ele perdeu para o Randômico mesmo tendo quase 3(três) vezes menos passos que o randômico, perdendo por 1000ms(mil milissegundos). Esse foi um caso em que a média do Randômico acabou sendo melhor que o BFS, mesmo em algum dos testes ele realizando valores muito maiores, sua média continuou sendo a menor mesmo com uma média alta de passos conferidos.  

<p> </p>

<p> </p>

# Conclusão

<p align="justify">
A partir dos testes realizados, foi possível perceber certos padrões relacionados aos BFS e DFS. Quanto mais longe o ponto de chegada estiver e mais próximos das bordas, mais o BFS demora para encontrar, pois pela sua lógica, ele sempre visitara todas as posições possíveis até o ponto de chegada. Enquanto ao DFS, ele se provou ser melhor que os outros dois na grande maioria dos casos, ele só perderá em tempo de execução para casos especificos onde o ponto de chegada se encontra mais próximo do ponto de partida e com paredes alocadas de maneiras específicas, e mesmo em seu pior dos casos, seus valores foram relativamente baixo. 

<p align="justify">
Com relação ao randomico, seu desempenho não foi relativamente ruim, apesar da média de passos ser extremamente imprevisel e altos, há casos em que ele pode ser melhor que os outros dois em tempo de execução mesmo com sua ainda alta média de passos, e casos em que ele vai ser o pior de todos. Mas devido a sua imprevisibilidade ele acaba por se tornar uma escolha perigosa para utilização.  

<p align="justify">
Logo, conlcuimos que, para um "tiro no escuro", seria melhor apostar no DFS para busca. O BFS apenas para buscas em casos específicos em que o se tem noção que o objetivo esteja próximo do ponto de partida. O Randômico é uma faca de dois gumes, não é recomendado a utilização pois, se pode ter uma maré de casos ruins, assim como de casos bons, sua imprevisibilidade não trás confiança na sua busca.

<p> </p>

<p> </p>

# Especificações do Dispositivo utilizado

|                                                                                                                            |
| -------------------------------------------------------------------------------------------------------------------------- |
|  `Processador`         -> Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz   1.99 GHz                                              |
|  `RAM Instalada`       -> 16.0 GB (utilizável: 15.8 GB)                                                                    |
|  `Tipo de Sistema`     -> Sistema operacional de 64 bits, processador baseado em x64                                       |
|  `Sistema Operacional` -> Edição Windows 10 Home Single Language, versão 21H2                                              |


<p> </p>

<p> </p>

# Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

<p> </p>

<p> </p>

# Contatos

<div style="display: inline-block;">
<a href="https://t.me/jmarconia">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/jmarconi-almeida/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>

<a style="color:black" href="mailto:jmarconiadm@outlook.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>jmarconiadm@outlook.com</i>
</a>
  
<a style="color:black" href="mailto:lucasfba13@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>lucasfba13@gmail.com</i>
</a>
