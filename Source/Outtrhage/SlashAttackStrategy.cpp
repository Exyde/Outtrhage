#include "AttackStrategy.h"
#include <memory>

namespace Outtrhage {

// Boilerplate derived attack strategy.
// Adjust method names/signatures to match your project's AttackStrategy interface.
class SlashAttackStrategy : public AttackStrategy {
public:
    SlashAttackStrategy();
    ~SlashAttackStrategy() override;

    // Example virtual overrides — replace with your project's actual methods:
    void Execute() override; // perform the attack
    std::unique_ptr<AttackStrategy> Clone() const override;

private:
    // Add fields needed for the slash attack (damage, range, animation id, etc.)
};

SlashAttackStrategy::SlashAttackStrategy() = default;
SlashAttackStrategy::~SlashAttackStrategy() = default;

void SlashAttackStrategy::Execute() {
    // TODO: implement slash behavior (apply damage, play effect, etc.)
}

std::unique_ptr<AttackStrategy> SlashAttackStrategy::Clone() const {
    return std::make_unique<SlashAttackStrategy>(*this);
}

} // namespace Outtrhage