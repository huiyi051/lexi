#ifndef PromptModuleH//��һ�δ���ͷ�ļ�ʱPromptModuleHδ�����壬���Բ��Գɹ�������#ifndef��������б�ִ��
#define PromptModuleH

namespace SAMSPrompt
{
    void PauseForUserAcknowledgement(void);
	bool UserWantsToContinue(const char * theThingWeAreDoing);
}

#endif