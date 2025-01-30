// Fill out your copyright notice in the Description page of Project Settings.


#include "Util/UDecision.h"

#include "DefaultGameMode.h"
#include "Considerations/ConsiderationBase.h"

FScoredAction* UDecision::Score(const FDecisionContext& Context) 
{
	// Get GameMode and the Package Manager
	ADefaultGameMode* GameMode = Cast<ADefaultGameMode>(Context.Actor->GetWorld()->GetAuthGameMode());

	FScoredAction* ScoredAction = new FScoredAction(); // Delete this later
	ScoredAction->ActionDef = ActionDef;
	ScoredAction->Target = Context.Target;

	TArray<float> Scores;

	for (UConsiderationBase* Consideration : Considerations)
	{
		float ConsiderationScore = Consideration->Score(Context);
		if (ConsiderationScore > 0)
			Scores.Add(ConsiderationScore);
	}

	if (Scores.Num() == 0)
	{
		// If no considerations are found, return a score of 0
		ScoredAction->Score = 0;
		return ScoredAction;
	}

	// Combine the scores
	ScoredAction->Score = CombineScores(Scores);
	return ScoredAction;
}

void UDecision::AddConsideration(UConsiderationBase* consideration)
{
	// Add the consideration
	Considerations.Add(consideration);
}

float UDecision::CombineScores(const TArray<float>& Scores)
{
	float sum = 0.0f;
	for (const float Score : Scores)
	{
		sum += Score;
	}

	return sum;

}
