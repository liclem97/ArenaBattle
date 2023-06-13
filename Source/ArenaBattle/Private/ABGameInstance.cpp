// 캐릭터 스탯 데이터 테이블 연결.

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

// 찾고자 하는 캐릭터 레벨의 데이터를 반환하는 함수.
FABCharacterData * UABGameInstance::GetABCharacterData(int32 Level)
{
	return ABCharacterTable->FindRow<FABCharacterData>(*FString::FromInt(Level), TEXT(""));
}