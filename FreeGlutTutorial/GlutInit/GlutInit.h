
namespace GlutInitialisation
{
    class GlutInit
    {
        public:
            GlutInit();
            void InitialiseWindow(int width, int height);
            void ChangeSize(int w, int h);
            void HandleSpecialKey(int key);
            void HandleRegularKey(unsigned char key);
    };
}
