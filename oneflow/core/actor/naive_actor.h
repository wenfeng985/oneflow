#ifndef ONEFLOW_CORE_ACTOR_NAIVE_ACTOR_H_
#define ONEFLOW_CORE_ACTOR_NAIVE_ACTOR_H_

#include "oneflow/core/actor/actor.h"

namespace oneflow {

class NaiveActor : public Actor {
 public:
  OF_DISALLOW_COPY_AND_MOVE(NaiveActor);
  NaiveActor() = default;
  ~NaiveActor() override = default;

  void VirtualActorInit(const TaskProto&) override {
    OF_SET_MSG_HANDLER(&NaiveActor::HandlerNormal);
  }

 private:
  void Act() final;
  std::pair<bool, std::vector<std::string>> GetNaiveConsumedRegstDescName() override {
    return {true, {}};
  }
};

}  // namespace oneflow

#endif  // ONEFLOW_CORE_ACTOR_NAIVE_ACTOR_H_
