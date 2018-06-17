#include "quirkymerchant.h"

QuirkyMerchant::QuirkyMerchant():
    IMerchant(),
    m_startSeq{BehaviorType::Cooperation, BehaviorType::Scam,
               BehaviorType::Cooperation, BehaviorType::Cooperation},
    m_opponentBehavior{BehaviorType::Cooperation},
    m_mustScam{false},
    m_currentStep{0}
{
}

IMerchant::BehaviorType QuirkyMerchant::doRightDecision()
{
    if (m_currentStep < 4){
        return m_startSeq[m_currentStep];
    }
    if (m_mustScam){
        return BehaviorType::Scam;
    }
    if (m_currentStep == 4){
        return BehaviorType::Cooperation;
    }
    return m_opponentBehavior;
}

IMerchant::BehaviorType QuirkyMerchant::doWrongDecision()
{
    BehaviorType b = doRightDecision();
    if (b == BehaviorType::Cooperation){
        return BehaviorType::Scam;
    }
    return BehaviorType::Cooperation;
}

void QuirkyMerchant::applyResultOfTransaction(IMerchant::profit_t p, IMerchant::BehaviorType opponentBehavior)
{
    IMerchant::applyResultOfTransaction(p, opponentBehavior);
    if (m_currentStep < 4){
        if (opponentBehavior == BehaviorType::Scam){
            //нас обманули до 5-го хода, теперь всегда жульничаем c 5-го хода
            m_mustScam = true;
        }
    }
    m_currentStep++;
    m_opponentBehavior = opponentBehavior;
}

void QuirkyMerchant::reset()
{
    IMerchant::reset();
    m_mustScam = false;
    m_currentStep = 0;
}
