#ifndef AccumulatorModuleH //��һ�δ���ͷ�ļ�ʱAccumulatorModuleHδ�����壬���Բ��Գɹ�������#ifndef��������б�ִ��
#define AccumulatorModuleH

struct aTapeElement
{
    char Operator;
	float Operand;
	aTapeElement *NextElement;
};

namespace SAMSCalcuator
{
	void PrintTape(aTapeElement *TapeRoot);
	void DeleteTape(aTapeElement **TapeRoot);
	void Tape(const char theOperator,const float theOperand = 0);
	bool TestOK(const char theOperator,const float theOperand,const float theExpectedResult);
	void SelfTest(void);
	float Accumulator(const char theOperator,const float theOperand = 0);
}

#endif