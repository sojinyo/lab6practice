#include <iostream>

int inputinteger();
void inputinteger(int& score); //overloading
bool appropriate(int score);
void showscoregrade(const int& score, char& grade); //함수 안에서 값을 바꾸지 못하도록
void scoregrade(const int&score=100, const char& grade='A');
// 함수 매개변수가 pass-by-value/reference인 경우와 함수 오버로딩을 구현해 봅니다.   
// 1. 함수 선언 후, 2. main에서 함수를 호출, 이후 3. 함수 정의를 합니다. 
// 1. 함수 선언: 함수이름은 식별자의 규칙에 따라 만듭니다.
// 1-0. 리턴형은 int형, 매개변수는 없음, 터미널로 int형 값을 입력받고 이를 리턴하는 함수를 선언 (lab5의 1-1과 같음)
// 1-1. 1-0과 함수이름을 같게 설정, 리턴 없음, 매개변수는 int형 참조 (총 1개), 터미널로 매개변수값을 입력받음, 
//      1-0과 함수이름은 같고 같은 작업을 하는데 매개변수와 리턴이 다를때 이를 ****이라고 함, ****를 주석으로 작성 
// 1-2. 리턴형은 bool형, 매개변수는 int형 1개, 매개변수가 0~100이면 true, 그렇지 않으면 false를 리턴하는 함수 선언 (lab5의 1-2와 같음)
// 1-3. 리턴 없음, 매개변수는 const int형 참조, char형 참조 (총 2개), int형 매개변수 값 (90이상,80이상,70이상,60이상,그외)에 따라 
//      char형에 ('A','B','C','D','F')값을 할당하는 함수 선언, int형 매개변수를 const한 이유를 주석으로 작성
// 1-4. 리턴 없음, 매개변수는 const int형 참조, const char형 참조 (총 2개), 기본값은 순서대로 100, 'A', 터미널로 매개변수 출력
int main()
{
    std::cout<<"01 kim sojin 2449008\n";
    int score{};
    std::cout<<"(In main)score address:"<<&score<<"\n";
    inputinteger(score); //참조이므로 실제인자의 주소를 전달받으므로
    if(!appropriate(score))  //값의 복사본을 전달받으므로 주소는 다름
    {
        exit(-1);
    }
    char grade{};
    showscoregrade(score,grade);
    scoregrade(score,grade);
    scoregrade(); //기본값이 있으므로
    return 0;
}
int inputinteger()
{
    int integer{};
    std::cout<<"Enter integer";
    std::cin>>integer;
    return integer;
}
void inputinteger(int& score) //overloading
{
    std::cout<<"(In integer)score address:"<<&score<<"\n";
    std::cout<<"Enter score";
    std::cin>>score;
}
bool appropriate(int score)
{
    std::cout<<"(In integer)score address:"<<&score<<"\n";
    return ( score>=0&&score<=100);
}
void showscoregrade(const int& score, char& grade) //함수 안에서 값을 바꾸지 못하도록
{
    if(score>=90) grade='A';
    else if(score>=80) grade='B';
    else if(score>=70) grade='C';
    else if(score>=60) grade='D';
    else grade='F';
}
void scoregrade(const int&score, const char& grade)
{
    std::cout<<score<<" "<<grade<<"\n";
}

// 2-0. 본인 분반, 본인 이름 그리고 학번을 순서대로 출력합니다. 
    //분반이 00분반, 이름이 Kim Programming, 학번이 3741200이라면, 00 Kim Programming 3741200 
// 2-1. 점수를 나타내는 int형 변수를 선언하고 주소 출력, 
    //      1-1함수호출(인자는 점수를 나타내는 int형 변수), 
    //      1-1함수호출시 매개변수의 주소를 출력하게 구현했는데 출력된 주소가 main의 점수를 나타내는 int형 변수의 주소와 같은 이유는? 
    
    // 2-2. 1-2함수(인자는 2-1변수)의 리턴값이 false면 프로그램 종료 (사전정의함수인 exit함수 사용), 
    //      1-2함수호출시 매개변수의 주소를 출력하게 구현했는데 출력된 주소가 main의 점수를 나타내는 int형 변수의 주소와 다른 이유는? 
    
    // 2-3. 성적을 나타내는 char형 변수를 선언하고, 1-3함수호출(인자는 점수를 나타내는 int형 변수, 성적을 나타내는 char형 변수)
    
    // 2-4. 1-4함수를 2번 호출 
    //      호출1. 인자로 점수를 나타내는 int형 변수, 성적을 나타내는 char형 변수를 넣어 호출 
    //      호출2. 인자를 넣지 않고 호출, 인자를 넣지 않아도 되는 이유는?
   // 3. 함수 정의
// 3-0. 1-0함수 정의 (lab5의 1-1과 같음) 
//      터미널로 int형 값을 입력받고 이를 리턴하는 함수
// 3-1. 1-1함수 정의: 터미널로 매개변수값을 입력받음
//      매개변수의 주소를 출력 
// 3-2. 1-2함수 정의: 매개변수가 0~100이면 true, 그렇지 않으면 false를 리턴하는 함수
//      매개변수의 주소 출력 (lab5의 1-2에 추가)
// 3-3. 1-3함수 정의: int형 매개변수 값 (90이상,80이상,70이상,60이상,그외)에 따라 
//      char형에 ('A','B','C','D','F')값을 할당하는 함수 
// 3-4. 1-4함수 정의: 매개변수 2개를 차례대로 출력