 class Robot {
      int total = 0;   
      bool moved = false;
      int w, h, perim;

  public:
      Robot(int width, int height) {
          w = width; h = height;
          perim = 2 * (w - 1) + 2 * (h - 1);
      }

      void step(int num) {
          total += num;
          total %= perim;
          if (num > 0) moved = true; 
      }

      vector<int> getPos() {
          int t = total;
          if (t < w)             
              return {t, 0};
          t -= w - 1;             
          if (t < h)               
              return {w - 1, t};
          t -= h - 1;              
          if (t < w) 
              return {w - 1 - t, h - 1};
          t -= w - 1;     
          return {0, h - 1 - t};
      }

      string getDir() {
          if (total == 0 && moved) return "South";
          if (total == 0)          return "East";   
          if (total < w)           return "East";
          if (total < w - 1 + h)   return "North";
          if (total < 2 * w - 2 + h)  return "West";
          return "South";
      }
  };