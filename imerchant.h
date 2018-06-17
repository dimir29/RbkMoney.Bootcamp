#pragma once

#include <string>

class IMerchant{
public:
    /// Тип поведения купца
    enum class BehaviorType: bool{
        Scam = 0,           ///< жульничество
        Cooperation = 1     ///< сотрудничество
    };


    using profit_t = unsigned int;

    IMerchant():
        m_profit{profit_t()}
    {}
    virtual ~IMerchant(){}

    /**
     * @brief Выполняет очередную сделку с другим купцом, делая правильное
     * решение исходя из своей стратегии поведения
     * @return тип поведения
     */
    virtual BehaviorType doRightDecision() = 0;
    /**
     * @brief Выполняет очередную сделку с другим купцом, делая ошибочное
     * решение исходя из своей стратегии поведения
     * @return
     */
    virtual BehaviorType doWrongDecision() = 0;

    /// общая прибыль купца
    virtual unsigned int getTotalProfit() const{
        return m_profit;
    }
    /// применить результаты сделки
    virtual void         applyResultOfTransaction(profit_t p, BehaviorType opponentBehavior){
        static_cast<void>(opponentBehavior);
        m_profit += p;
    }
    virtual void reset() {
        m_profit = 0;
    }

    /// получить символьное описание купца - тип стратегии и текущую общую прибыль
    virtual std::string          getDescription() const = 0;

    /// создаёт нового купца с таким-же поведением, как и у оригинала
    virtual IMerchant*          createNewMerchant() const = 0;

protected:
    profit_t m_profit;

};
