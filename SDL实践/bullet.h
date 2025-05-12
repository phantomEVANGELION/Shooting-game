#pragma once
#include "camera.h"
#include "vector2.h"
#include <SDL.h>
extern SDL_Texture* tex_bullet;// �ⲿ�������
class Bullet {
public:
    Bullet(double angle)// ���캯��
    {
        this->angle = angle;
        double radians=angle*3.14159265/180;// �Ƕ�ת����
        velocity.x=(float)std::cos(radians)*speed;
        velocity.y=(float)std::sin(radians)*speed;
    }
    ~Bullet() = default;
    void set_position(const Vector2& position)// �����ӵ���λ��
    {
        this->position = position;
    }
    const Vector2& get_position()const// ��ȡ�ӵ���λ��
    {
        return position;
    }
    void on_update(float delta)// �����ӵ���λ��
    {
        position += velocity*delta;
        if(position.x<=0||position.x>=1280||position.y<=0||position.y>=720)// �ӵ�������Ļ��Χ����ɾ���ӵ�
        {
            is_valid = false;
        }
    }
    void on_render(const Camera& camera)const
    {
        const SDL_FRect rect_bullet = {position.x-4,position.y-2,8,4};//  �ӵ��ľ���
        camera.render_texture(tex_bullet,nullptr,&rect_bullet,angle,nullptr);//�����ӵ�
    }
    void on_hit()
    {
        is_valid = false;
    }
    bool can_move()const//  �ӵ��Ƿ�����ƶ�
    {
        return !is_valid;
    }
private:
    double angle = 0;
    Vector2 position;
    Vector2 velocity;
    bool is_valid = true;// �ӵ��Ƿ�����ƶ�
    float speed = 800.0f;
};