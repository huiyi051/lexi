#ifndef AccumulatorModuleH //第一次处理头文件时AccumulatorModuleH未被定义，所以测试成功，跟在#ifndef后的所有行被执行
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