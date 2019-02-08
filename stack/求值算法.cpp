#include<iostream>
#include<stack>
#define N_OPTR 9//运算符总数
using namespace std;
typedef enum{ADD,SUB,MUL,DIV,POW,FAC,L_P,R_P,EOE}Operator;//运算符集合（枚举类型）
//+ - * / ^ ! ( ) \0
const char pri[N_OPTR][N_OPTR] = {//详细表见onenote/数/栈
 '>','>','<','<','<','<','<','>','>',
  '>','>','<','<','<','<','<','>','>',
   '>','>', '>','>','<','<','<','>','>',
	'>','>', '>','>','<','<','<','>','>',
	'>','>','>','>','>','<','<','>','>',
	'>','>','>','>','>','>',' ','>','>',
	'<','<','<','<','<','<','<','=',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',
	'<','<','<','<','<','<','<',' ','=',
};

bool isDigit(char s)
{
	if (48<=int(s)&&int(s)<=57)
	{
		return true;
	}
	return false;
}
void readNumber(stack<float>&Opnd,char *&S)//指针引用：具体可见onenote指针
{
	float tem=float(*S-'0');//坑：记得不能直接输出ascii码要减去某个数
	while (isDigit(*(++S)))//下一个也是数字时
	{
		tem = tem * 10 + float(*S-'0');
	}
	Opnd.push(tem);
	if ('.' != *S) return;//判断有无小数部分
		float fraction = 1;
		tem = Opnd.top(); Opnd.pop();
	while (isDigit(*(++S)))
	{
		tem = tem + float(*S - '0')*(fraction /= 10);
	}
	Opnd.push(tem);
}
char ChangeOp(char op)//将运算符转化为对应枚举类型
{
	switch (op)
	{
	case'+':return ADD;
		break;//ADD,SUB,MUL,DIV,POW,FAC,L_P,R_P,EOE+ - * / ^ ! ( ) \0
	case'-':return SUB;
		break;
	case'*':return MUL;
		break;
	case'/':return DIV;
		break;
	case'^':return POW;
		break;
	case'!':return FAC;
		break;
	case'(':return L_P;
		break;
	case')':return R_P;
		break;
	case'\0':return EOE;
		break;

	default:
		break;
	}
}
char OrderBetween(char op,char S)
{
	return pri[ChangeOp(op)][ChangeOp(S)];
}
float caculate(float num, char op)//！运算情况
{
	float sum = 1;
	for(int i = 1; i <= int(num); i++)
{
		sum *= i;
}
	return sum;
}
float caculate(float n1, char op, float n2)//双目运算符情况
{
	switch (op)
	{
		
	case'+':return n1+n2;
	case'-':return n1-n2;
	case'*':return n1*n2;
	case'/':return n1/n2;
	case'^':
	{	float sum = 1;
	while (n2--)
	{
		sum *= n1;
	};
	return sum; 
	}
	default:
		exit(-1);
		
	}
}

float evaluate(char * S)
{
	stack<float>Opnd;
	stack<char>Optr;//运算数栈，运算符栈
	Optr.push('\0');//尾哨兵（为了和最后S中的\0配对）
	while (!Optr.empty())
	{
		if (isDigit(*S))//如果是数字
		{
			readNumber(Opnd, S);//将数字入栈（坑在于多位数的处理）

		}
		else
		{
			switch (OrderBetween(Optr.top(), *S))//比较操作符栈顶元素和当前多项式的符号的优先级
			{
				case '<':
				{Optr.push(*S);
				S++;
				break; }
				case '=':
				{Optr.pop();
				S++;
				break; }
				case'>':
				{ char op = Optr.top(); Optr.pop();
				float ptop = Opnd.top(); Opnd.pop();
				float end;
				if (op == '!')
					end = caculate(ptop, op);
				else
				{
					float pptop = Opnd.top(); Opnd.pop();
					end = caculate(ptop, op, pptop);
				}
				Opnd.push(end);
				break; }
				default:exit(-1);

			}
			
		}
	}
	return Opnd.top();
}

int main()
{
	char s[20] = "1+(10+20)*12+5";
	cout << evaluate(s) << endl;
	system("pause");

}