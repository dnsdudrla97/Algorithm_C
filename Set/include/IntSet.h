/* int형 집합 intSet(헤더 부분) */
#ifndef ___IntSet
#define ___IntSet

/*--- int형 집합을 관리하는 구조체 ---*/
typedef struct
{
	int max;		/*집합의 크기*/
	int num;		/*집합의 원소 개수*/
	int* set;		/*집합 본체의 배열(의 첫 번째 요소에 대한 포인터)*/
} intSet;


/*--- 집합 초기화 ---*/
int Init(intSet *s, int max);

/*--- 집합 s에 n이 들어있는지 확인 ---*/
int IsMember(const intSet *s, int n);

/*--- 집합 s에 n을 추가 ---*/
void Add(intSet *s, int n);

/*--- 집합 s에서 n을 삭제 ---*/
void Remove(intSet *s, int n);

/*--- 집합 s에 넣을 수 있는 최대 원소 개수를 반환 ---*/
int Capacity(const intSet *s);

/*--- 집합 s의 원소 개수 ---*/
int Size(const intSet *s);

/*--- 집합 s2를 s1에 대입 ---*/
void Assign(intSet *s1, const intSet *s2);

/*--- 집합 s1과 s2가 같은지 확인 ---*/
int Equal(const intSet *s1, const intSet *s2);

/*--- 집합 s2와 s3의 합집합을 s1에 대입 ---*/
intSet *Union(intSet *s1, const intSet *s2, const intSet *s3);

/*--- 집합 s2와 s3의 교집합을 s1에 대입 ---*/
intSet *Intersection(intSet *s1, const intSet *s2, const intSet *s3);

/*--- 집합 s2에서 s3을 뺀 차집합을 s1에 대입 ---*/
intSet *Difference(intSet *s1, const intSet *s2, const intSet *s3);

/*--- 집합 s의 모든 원소를 ​​출력 ---*/
void Print(const intSet *s);

/*--- 집합 s의 모든 원소를 ​​출력(줄 바꿈 문자 포함) ---*/
void PrintLn(const intSet *s);

/*--- 집합을 메모리에서 제거 ---*/
void Terminate(intSet *s);


/* -- context add -- */

/*집합이 가득 찼다면 1, 아니면 0을 반환 */
int IsFull(const intSet* s);

/*집합의 모든 원소를 삭제하는 함수 */
void Clear(intSet(* s));

/*집합 s2, s3의 대칭 차를 s1에 대입하는 함수*/
intSet* SymmetricDifference(intSet* s, const intSet* s2, const intSet* s3);

/*집합 s1에 s2의 모든 원소를 추가하는 함수(s1 포인터 반환)*/
intSet* ToUnion(intSet* s1, const intSet* s2);

/*집합 s1에서 s2에 들어 있지 않은 모든 원소를 삭제하는 함수(s1 포인터 반환)*/
intSet* ToIntersection(intSet* s1, const intSet* s2);

/*집합 s1에서 s2에 들어 있는 모든 원소를 삭제하는 함수(s1 포인터 반환)*/
intSet* ToDifference(intSet* s1, const intSet* s2);

/*집합 s1이 s2의 부분집합이면 1, 아니면 0을 반환*/
int IsSubset(const intSet* s1, const intSet* s2);

/*집합 s1이 s2의 진부분집합이면 1, 아니면 0을 반환*/
int IsProperSubset(const intSet* s1, const intSet* s2);

#endif