#include "dodgermerchant.h"

DodgerMerchant::DodgerMerchant():
    IMerchant(),
    m_isFirstStep{true},
    m_opponentDecision{BehaviorType::Cooperation}
{
}

IMerchant::BehaviorType DodgerMerchant::doRightDecision()
{
    if (m_isFirstStep){
        return BehaviorType::Cooperation;
    }else{
        return m_opponentDecision;
    }
}

IMerchant::BehaviorType DodgerMerchant::doWrongDecision()
{
    if (m_isFirstStep){
        return BehaviorType::Scam;
    }else{
        return (m_opponentDecision==BehaviorType::Cooperation)?
                        BehaviorType::Scam:
                        BehaviorType::Cooperation;
    }
}

void DodgerMerchant::applyResultOfTransaction(IMerchant::profit_t p, IMerchant::BehaviorType opponentBehavior)
{
    IMerchant::applyResultOfTransaction(p, opponentBehavior);
    m_opponentDecision = opponentBehavior;
    m_isFirstStep = false;
}

void DodgerMerchant::reset()
{
    IMerchant::reset();
    m_isFirstStep = true;
}
