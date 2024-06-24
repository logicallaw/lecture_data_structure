/*
1일차
0.노드란 데이터 저장 단위를 의미한다.
또한, 노드 간 연결은 포인터(또는 링크)로 연결한다.
1.Array:임의의 인덱스에 빠르게 접근 가능한 장점.
단, 미리 메모리 Size를 정하는 단점이 있음.
2.링크드 리스트(연결 리스트):데이터 저장할 Size를 미리 정할 필요가 없는게 장점(계속해서 데이터 저장 가능)
단, 임의의 노드(=데이터 저장 단위)의 주소 값을 모르면 빠르게 접근하는 방법이 없음. 따라서, 접근하고 싶다면 앞에서부터 확인하면서 탐색 해야한다.
3.연결 리스트(링크드 리스트)는 세 가지 종류로 나뉜다.
 -1)singly linked list:특정노드에서 다음노드 주소를 저장한다. (기본).
 -2)double linked list:내앞의 노드 주소, 다음 노드 주소 저장.
 -3)circularly linked list:기본 1번에서 마지막노드가 NULL이 아닌 맨 앞의 노드 주소를 저장.
4.before/after relation:물리적이 아닌 개념적인 상대적 위치 관계를 의미.
예를 들면, 1000번지 노드의 다음 노드가 100번지라면, 물리적으로는 뒤에 있지만, 개념적으로는 상대적으로 100번지에 비해 앞에 존재한다.
5.element는 데이터를 저장할 원소를 의미하고, next(=pointer, link)는 다음 노드 주소를 저장한다.
6.linked list는 보통 head, tail로 관리하며 head, tail을 통해 노드에 접근한다. 중간에 접근할 수가 없다.
7.링크드 리스트는 기본적으로 노드 class와 node를 관리하는 링크드 리스트 클래스 두개로 구현한다.

8.Singly linked list는 맨 마지막 노드의 next가 NULL인 리스트를 말한다.
9.StringNode 클래스에서 next는 StringNode의 크기인 포인터를 의미한다.
10.Singly linked list 메서드별 기능
 empty():linked list 노드가 아에 없으면 true 리턴
 front():linked list 가장 맨 앞에 있는 노드의 element를 리턴
 addFront():맨 앞 삽입 연산
 removeFront():맨 앞 노드 삭제 연산
 addBack():맨 뒤 삽입 연산
 removeBack():맨 뒤 노드 삭제 연산
11.addFront()
 추가할 element를 받는다.
 노드 크기 만큼 동적할당 한 뒤에 주소값에 v를 저장한다.
 일반적으로 v의 element에는 인자로 받은 값을 저장.
 v의 next에는 기존 head가 가리키는 주소로 업데이트.
 기존 head는 새로 추가된 노드인 v로 업데이트
   특이 케이스 0개인 경우:노드가 비어있을 때 경우에 따라 tail도 업데이트 해야한다.
   tail = v를 가리키게 해야한다.
12.removeFront()
 removeFront는 그냥 삭제시 다음 노드 주소값을 알 수 없어서 임시 변수가 필요
   0개인 경우:
     지울게 없어서 return한다.

   2개 이상인 경우(일반적 상황):임시 변수 old는 head를 저장
   head는 삭제 전에 다음 노드 주소 값으로 업데이트한다.
   그 다음 기존 임시 변수를 delete한다.

   특이 케이스 1개인 경우:
   tail은 NULL로 업데이트한다.

13.addBack()
 새로운 노드를 동적할당 받는다.
 v->elem = e
 v->next = NULL
 특이 케이스 0개인 경우:
   head = tail = v;
 0개가 아닌 경우(else):
   tail->next = v;
   tail = v;
14.removeBack():
전제 조건:LinkedList의 접근은 기본적으로 head, tail 밖에 없어서
 주소값을 모르면 둘 중 하나로 접근해야됨.
 그러나, 꼬리 삭제 연산은 꼬리의 이전 노드의 주소를 모르기 때문에 맨 앞부터 탐색해야한다.

 특이케이스 0개 : 비어있으면 return 한다.
 current = head
 특이케이스 1개 :
   if(current == tail)
     head = tail = NULL (삭제전 NULL로)
     delete current (임시 변수 delete함)
 else 2개 이상인 경우:(탐색)
   while(current -> next != tail){
     current = current->next //current를 다음 노드로 업데이트
   } //tail 앞의 노드를 찾는 과정.
   tail = current
   delete tail->next
   tail->next = NULL

 */