#pragma once

#include "utils.hpp"

namespace insectum::verlet
{
    class Object
    {
        public:
            Object(float x, float y, float size);
            Object(insectum::Vec2 position, float size);
            ~Object();
            float getRadius() { return radius_; }
               insectum::Vec2 getPosition() { return position_; }
            insectum::Vec2 getVelocity();
            bool isFixed(){ return fixed_; }

            void setPosition(insectum::Vec2 newPosition) { position_ = newPosition; }
            void setVelocity(insectum::Vec2 v);
            void addVelocity(insectum::Vec2 v);
            void addAcceleration(insectum::Vec2 a) { acceleration_ = acceleration_ + a; }
            void setAcceleration(insectum::Vec2 a) { acceleration_ = a; }
            void setFixed(bool fixed) { fixed_ = fixed; }

            void update(float dt);

        private:
            float radius_;
            insectum::Vec2 position_;
            insectum::Vec2 prevPosition_;
            insectum::Vec2 newVelocity_;
            insectum::Vec2 acceleration_;
            bool fixed_ = false;
    };
}
