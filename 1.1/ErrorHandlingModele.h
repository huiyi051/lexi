#ifndef ErrorHandlingModuleH//��һ�δ���ͷ�ļ�ʱErrorHandlingModuleHδ�����壬���Բ��Գɹ�������#ifndef��������б�ִ��
#define ErrorHandlingModuleH


namespace SAMSErrorHandling
{
   void Initialize(void);
   int HandleNotANumberError(void);
   int HandleRuntimeErorr(std::runtime_error RuntimeError);
}

#endif