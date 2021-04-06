# SOII
Espaço para a organização das atividades da disciplina de Sistemas Operacionais II.


### Primeira Atividade - Programando com PThreads
Na tabela abaixo, segue uma avaliação dos tempos de execução do programa [pt_join.c](https://github.com/MGStigger/SOII/blob/main/pt_join.c), variando o número de threads e ajustando o seu número de iterações.
| N° de Threads |   T.P.   | Tempo Gasto |
|     :---:     |   :---:  |    :---:    |
|       4       |   10<sup>12</sup>  | 3 min 43 seg|
|       4       |   10<sup>11</sup>  |    22 seg   |
|       4       |   10<sup>10</sup>  |    2 seg    |
|       3       |   10<sup>12</sup>  |    4 min    |
|       3       |   10<sup>11</sup>  |    24 seg   |
|       3       |   10<sup>10</sup>  |    3 seg    |
|       2       |   10<sup>12</sup>  | 3 min 57 seg|
|       2       |   10<sup>11</sup>  |    25 seg   |
|       2       |   10<sup>10</sup>  |    3 seg    |
|       1       |   10<sup>12</sup>  | 7 min 24 seg|
|       1       |   10<sup>11</sup>  |    44 seg   |
|       1       |   10<sup>10</sup>  |    5 seg    |

**Equipamento utilizado**: Processador Intel(R) Core(TM) i3-2348M CPU @ 2.30GHz 2.30 GHz (2 núcleos físicos e 4 núcleos lógicos).
