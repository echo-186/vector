#include<iostream>
#include<stack>
#define N_OPTR 9//���������
using namespace std;
typedef enum{ADD,SUB,MUL,DIV,POW,FAC,L_P,R_P,EOE}Operator;//��������ϣ�ö�����ͣ�
//+ - * / ^ ! ( ) \0
const char pri[N_OPTR][N_OPTR] = {//��ϸ���onenote/��/ջ
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
void readNumber(stack<float>&Opnd,char *&S)//ָ�����ã�����ɼ�onenoteָ��
{
	float tem=float(*S-'0');//�ӣ��ǵò���ֱ�����ascii��Ҫ��ȥĳ����
	while (isDigit(*(++S)))//��һ��Ҳ������ʱ
	{
		tem = tem * 10 + float(*S-'0');
	}
	Opnd.push(tem);
	if ('.' != *S) return;//�ж�����С������
		float fraction = 1;
		tem = Opnd.top(); Opnd.pop();
	while (isDigit(*(++S)))
	{
		tem = tem + float(*S - '0')*(fraction /= 10);
	}
	Opnd.push(tem);
}
char ChangeOp(char op)//�������ת��Ϊ��Ӧö������
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
float caculate(float num, char op)//���������
{
	float sum = 1;
	for(int i = 1; i <= int(num); i++)
{
		sum *= i;
}
	return sum;
}
float caculate(float n1, char op, float n2)//˫Ŀ��������
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
	stack<char>Optr;//������ջ�������ջ
	Optr.push('\0');//β�ڱ���Ϊ�˺����S�е�\0��ԣ�
	while (!Optr.empty())
	{
		if (isDigit(*S))//���������
		{
			readNumber(Opnd, S);//��������ջ�������ڶ�λ���Ĵ���

		}
		else
		{
			switch (OrderBetween(Optr.top(), *S))//�Ƚϲ�����ջ��Ԫ�غ͵�ǰ����ʽ�ķ��ŵ����ȼ�
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