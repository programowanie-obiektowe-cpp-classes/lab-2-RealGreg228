#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
    public:
    ResourceManager() : resource_(new Resource()) { }

    ResourceManager(const ResourceManager& other) : resource_(new Resource(*other.resource_)) { }

    ~ResourceManager() { delete resource_; }

    double get() const{
        return resource_->get();
    }

    ResourceManager& operator=(const ResourceManager& other){
        if(this != &other){
            delete resource_;
            resource_ = new Resource(*other.resource_);
        }
        return *this;
    } 

    // Przenoszenie
    ResourceManager(ResourceManager&& other) noexcept : resource_(other.resource_){
        other.resource_ = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept{
        if(this!=&other){
            delete resource_;
            resource_ = other.resource_;
            other.resource_ = nullptr;
        }
        return *this;
    }

    private:
    Resource* resource_;
};
