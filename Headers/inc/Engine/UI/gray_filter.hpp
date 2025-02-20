#include "ui_element.hpp"
#include "image_visual_component.hpp"

class GrayFilter : public UI_Element {
private:
    Camera* camera;
public:
    GrayFilter(WindowManager* WM, Camera* _camera);
    virtual ~GrayFilter() = default;

    void Update() override;
};