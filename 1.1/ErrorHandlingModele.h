#ifndef ErrorHandlingModuleH//第一次处理头文件时ErrorHandlingModuleH未被定义，所以测试成功，跟在#ifndef后的所有行被执行
#define ErrorHandlingModuleH


namespace SAMSErrorHandling
{
   void Initialize(void);
   int HandleNotANumberError(void);
   int HandleRuntimeErorr(std::runtime_error RuntimeError);
}

#endif