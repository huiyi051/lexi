#ifndef PromptModuleH//第一次处理头文件时PromptModuleH未被定义，所以测试成功，跟在#ifndef后的所有行被执行
#define PromptModuleH

namespace SAMSPrompt
{
    void PauseForUserAcknowledgement(void);
	bool UserWantsToContinue(const char * theThingWeAreDoing);
}

#endif