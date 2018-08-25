//original codes by http://milvus.tistory.com/22
//caption by Ayoung Lee

#include <stdio.h>

typedef struct _node //노드 선언
{
  int value; // node가 가지고 있는 데이터
  struct _node* next; // 다음 node의 주소를 담고 있는 노트포인터
} node;

typedef node* nptr; //노드포인터

typedef struct _queue
{
  int count; // 현재 queue 에 들어있는 노드의 개수
  nptr front; // 맨앞 노드 (지워질 노드)
  nptr rear; // 맨뒤 노드 (추가될 노드)
} queue;

///
queue* create_queue (void);
void destroy_queue (queue* qptr);
void add_rear (queue* qptr, int value);
int remove_front (queue*);
///

//동적할당된 큐는 queue* 라는 자료형을 가지고 있다고 생각하면 이해하기 편함

int main ()
{
    queue* myqueue=create_queue();
    add_rear(myqueue,1);
    add_rear(myqueue,2);
    add_rear(myqueue,3);
    destroy_queue(myqueue);
    return 0;
}

queue * create_queue () // queue사이즈만큼 메모리를 동적할당하여 큐형 포인터를 리턴 (?)
// 다른 함수를 만들때 queue* myqueue=create_queue(); 이런식으로 동적할당하게 해주나봄
{
  queue *new_queue = (queue *) malloc (sizeof (queue)); //queue만큼 동적할당
  new_queue->count = 0; //새로 만들어진 new_queue의 node의 개수는 0이므로 0으로 초기화
  new_queue->front = NULL; //new_queue->front도 초기화
  new_queue->rear = NULL; //new_queue->rear도 초기화
  return new_queue;
}

void destroy_queue (queue * qptr)//queue의 모든 노드를 삭제하고 queue자신의 동적할당한 메모리도 반납한다.
//숫자만 받아오는 것이 아니라 queue 의 값을 변경해야 하므로 포인터로 받아온다.
{
    //여기서 qptr은 동적할당된 queue*
  while (qptr->count != 0) //해당 queue에 들어있는 모든 노드의 개수가 0이 아닐 동안 반복
    {
      remove_front (qptr); //앞에서부터 지움
    }
  free (qptr); // 모든 노드를 삭제하고 마지막으로 동적할당된 queue도 삭제함.
  printf ("Queue Destroy Complete");
}

void add_rear (queue * qptr, int value)
{
  nptr new_node = (nptr) malloc (sizeof (node)); //새로운 노드를 동적할당
  new_node->value = value; //new node->value에 함수에서 입력받은 value값을 할당
  new_node->next = NULL; //new_node->next 초기화

  if (qptr->count == 0) // queue에서 첫번째로 입력받는 node라면
    {
      qptr->front = new_node; //지워질 노드도 새로 생성된 노드
      qptr->rear = new_node; //생성될 노드도 새로 생성된 노드 뒤
    }
  else //queue에 다른 node가 존재한다면
    { 
      qptr->rear->next = new_node; //맨 뒤에 있던 node의 next에 new_node
      qptr->rear=new_node; //queue의 rear값은 원래 맨 뒤에있던 node에서 new_node로 바꾼다
    }
    //왜 주소값인 next에 new_node로 바로 저장됬을까..? new_node는 node라는 struct로써 이름값이고
    //new_node안의 값에 접근하기 위해서는 new_node->xx 이런식으로 접근해야한다
  qptr->count++; //새로운 node가 추가됬으므로 count의 값을 1 올린다.
}

int remove_front(queue* qptr)//queue의 맨 앞의 값을 지우는 함수
// 이 함수는 그림 그리면서 생각해야 편하다.ㅠㅠ
{
    if (qptr->count==0)//아무 노드도 queue에 존재하지 않을때
    {
        printf("There is no item in this queue. \n")
        return -1; // 오류라서 -1반환
    }
    else//queue에 노드가 존재할 때
    {
        nptr tmp=qptr->front; //tmp라는 노드 포인터형 함수를 만들어 원래 queue에 들어있던 front값을 저장
        qptr->front=tmp->next; //queue의 front값은 원래 맨첨에 queue에 들어있던 node값의 다음 주소값으로 변경
        int tmp_value=tmp->value; //tmp_value라는 int형 변수를 만들어서 tmp->value의 값을 저장해놓는다. 바꿀거니까...
        free(tmp); // 동적할당한 tmp를 해제해주는 건데 아직 잘 모르겠다. tmp가 동적할당됬는지는 모르겠고 qptr이 동적할당 된것 같은데...
        qptr->count--;// qptr의 count값을 내림 하나 해제했으니까
        return tmp_value; // 반환은 제거 전 앞에 들어있던 노드의 삭제된 value값을 반환한다.
    }
}
