#pragma once
#include "camera.h"
#include "vector2.h"
#include <SDL.h>
extern SDL_Texture* tex_bullet;// 外部纹理对象
class Bullet {
public:
    Bullet(double angle)// 构造函数
    {
        this->angle = angle;
        double radians=angle*3.14159265/180;// 角度转弧度
        velocity.x=(float)std::cos(radians)*speed;
        velocity.y=(float)std::sin(radians)*speed;
    }
    ~Bullet() = default;
    void set_position(const Vector2& position)// 设置子弹的位置
    {
        this->position = position;
    }
    const Vector2& get_position()const// 获取子弹的位置
    {
        return position;
    }
    void on_update(float delta)// 更新子弹的位置
    {
        position += velocity*delta;
        if(position.x<=0||position.x>=1280||position.y<=0||position.y>=720)// 子弹超出屏幕范围，则删除子弹
        {
            is_valid = false;
        }
    }
    void on_render(const Camera& camera)const
    {
        const SDL_FRect rect_bullet = {position.x-4,position.y-2,8,4};//  子弹的矩形
        camera.render_texture(tex_bullet,nullptr,&rect_bullet,angle,nullptr);//绘制子弹
    }
    void on_hit()
    {
        is_valid = false;
    }
    bool can_move()const//  子弹是否可以移动
    {
        return !is_valid;
    }
private:
    double angle = 0;
    Vector2 position;
    Vector2 velocity;
    bool is_valid = true;// 子弹是否可以移动
    float speed = 800.0f;
};