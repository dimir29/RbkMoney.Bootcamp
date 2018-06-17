#include "rancorousmerchant.h"

RancorousMerchant::RancorousMerchant():
    IMerchant(),
    m_mustScam{false}
{
}

void RancorousMerchant::applyResultOfTransaction(IMerchant::profit_t p, IMerchant::BehaviorType opponentBehavior)
{
    IMerchant::applyResultOfTransaction(p, opponentBehavior);
    if (opponentBehavior == BehaviorType::Scam){
        m_mustScam = true;
    }
}

void RancorousMerchant::reset()
{
    IMerchant::reset();
    m_mustScam = false;
}
