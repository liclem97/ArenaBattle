// ĳ���� ���� ������ ���̺� ����.

#include "ABGameInstance.h"


UABGameInstance::UABGameInstance()
{
	FString CharacterDataPath = TEXT("DataTable'/Game/Book/GameData/ABCharacterData.ABCharacterData'");
	static ConstructorHelpers::FObjectFinder<UDataTable>
		DT_ABCHARACTER(*CharacterDataPath);

	ABCHECK(DT_ABCHARACTER.Succeeded());
	ABCharacterTable = DT_ABCHARACTER.Object;
	ABCHECK(ABCharacterTable->GetRowNames().Num() > 0);
}

void UABGameInstance::Init()
{
	Super::Init();
}

// ã���� �ϴ� ĳ���� ������ �����͸� ��ȯ�ϴ� �Լ�.
FABCharacterData * UABGameInstance::GetABCharacterData(int32 Level)
{
	return ABCharacterTable->FindRow<FABCharacterData>(*FString::FromInt(Level), TEXT(""));
}