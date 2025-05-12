#ifndef _ATLAS_H
#define _ATLAS_H

#include <SDL.h>
#include <SDL_image.h>

#include <vector>
#include <string>
class Atlas
{
public:
    Atlas() = default;
    ~Atlas()
    {
        for(SDL_Texture* texture : tex_list)
            SDL_DestroyTexture(texture);
    }
    void load(SDL_Renderer* renderer, const char* path_template,int num)
    {
        for (int i = 0; i < num; i++)
        {
            char path_file[256];
            sprintf_s(path_file, path_template, i + 1);
            SDL_Texture*texture=IMG_LoadTexture(renderer, path_file);
            tex_list.push_back(texture);
        }
    }
    void clear()//ɾ����������
    {
        tex_list.clear();
    }
    int get_size()const//��ȡ��������
    {
        return (int)tex_list.size();
    }
    SDL_Texture* get_texture(int idx)//��ȡ����(ָ���±�)
    {
        if(idx<0||idx>=tex_list.size())
            return nullptr;
        return tex_list[idx];
    }
    void add_texture(SDL_Texture* texture)//�������
    {
        tex_list.push_back(texture);
    }
private:
    std::vector<SDL_Texture*> tex_list;
};
#endif