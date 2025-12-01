#include "AttackStrategy.h"
#include <memory>

namespace Outtrhage {

// Boilerplate derived attack strategy.
// Adjust method names/signatures to match your project's AttackStrategy interface.
class SlashAttackStrategy : public IAttackStrategy {
public:
    SlashAttackStrategy();
    ~SlashAttackStrategy() override;

    // Example virtual overrides — replace with your project's actual methods:
    void Execute() override; // perform the attack

private:
    // Add fields needed for the slash attack (damage, range, animation id, etc.)
};

SlashAttackStrategy::SlashAttackStrategy() = default;
SlashAttackStrategy::~SlashAttackStrategy() = default;

void SlashAttackStrategy::Execute() {
    // TODO: implement slash behavior (apply damage, play effect, etc.)
}

} // namespace Outtrhage