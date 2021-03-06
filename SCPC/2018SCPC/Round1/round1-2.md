## Round 1 - 2 회문인 수의 합

회문(回文)인 숫자는 왼쪽에서 읽으나, 오른쪽에서 읽으나 같은 숫자를 말한다. 예를 들어, 3, 121, 13231, 263362는 회문인 숫자이다.   어떤 수 nn이 주어졌을 때, 이 nn을 회문인 숫자 최대 3개의 합으로 표현할 수 있는지 없는지 알려주고, 있다면 회문인 숫자들의 **최소 갯수**의 합으로 표현하는 프로그램을 작성하시오.  예를 들어, 121은 그 자체가 회문인 숫자이므로 1개의 회문인 숫자 121로 표현이 가능하며, 15233은 15233 = 13231+2002과 같이 회문인 숫자 두 개의 합으로 나타낼 수 있다. 15237은 15237 = 13231 + 2002 + 4와 같이 회문인 숫자 세 개의 합으로 표현이 가능하다. 회문인 숫자들 중 같은 값이 있는 것도 허용된다.   

- 제한시간: 전체 테스트 케이스는 30개 이하이며, 전체 수행 시간은 1초 이내. (Java 2초 이내) 



#### input

입력 파일에는 여러 테스트 케이스가 포함될 수 있다. 파일의 첫째 줄에 테스트 케이스의 개수를 나타내는 자연수 TT가 주어지고, 이후 차례로  TT개의 테스트 케이스가 주어진다. (1≤T≤30)(1≤T≤30) 각 테스트 케이스는 정확하게 하나의 정수 n(1≤n≤10,000)n(1≤n≤10,000)이 주어지며, 이 숫자가 최대 3개의 회문인 숫자들의 합으로 표현할 수 있는지 알아보려는 숫자이다.    

- 점수 : 최대 10회 제출하여 취득한 각각의 점수 중에서 최대 점수 (만점 100점)   주어지는 테스트 케이스 데이터들의 그룹은 아래와 같으며,   각 그룹의 테스트 케이스를 모두 맞추었을 때 해당되는 부분 점수를 받을 수 있다.    
  - 그룹 1 (21 점) : 이 그룹의 테스트 케이스에서는 n≤100.    
  - 그룹 2 (27 점) : 이 그룹의 테스트 케이스에서는 n≤1,000.    
  - 그룹 3 (52 점) : 이 그룹의 테스트 케이스에서는 추가적인 제약 사항이 없다. 



#### output

각 테스트 케이스의 답을 순서대로 표준출력으로 출력하여야 하며, 각 테스트 케이스마다 첫 줄에는 “Case #C”를 출력하여야 한다. 이때 C는 테스트 케이스의 번호이다. 그 다음 줄에 최대 4개의 정수를 출력한다. 처음 숫자 KK는, 입력받은 nn이 몇 개의 회문인 숫자의 합인지를 나타낸다. 만약 불가능하다면 0을 출력한다. 그 다음 KK개의 숫자는, 합이 nn이 되는 KK개의 회문인 숫자를 크기의 내림차순으로 출력한다. KK개의 숫자로 표현 가능한 둘 이상의 경우가 있다면, 이 중 하나를 출력한다. 



