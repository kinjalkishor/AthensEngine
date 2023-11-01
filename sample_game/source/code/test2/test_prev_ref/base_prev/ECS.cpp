
// A simple EC framework would look something like this:
// Building features in an EC framework generally means inheriting from an IComponent interface, 
// and composing entities from multiple components. An example of EC in practice is Unity's GameObject system.
class IComponent {
public:
    virtual void update() = 0;
};
class Entity {
    std::vector<IComponent*> components;
public:
    void addComponent(IComponent *component);
    void removeComponent(IComponent *component);
    void updateComponents();
};
