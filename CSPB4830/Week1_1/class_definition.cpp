class Notebook
{
  public:
    Notebook()
    {
      paper_type_ = "none";
      num_pages_ = 0;
    }
    Notebook(std::string paper_type, int num_pages)
    {
      paper_type_ = paper_type;
      num_pages_ = num_pages;
    }

  private:
    std::string paper_type_;
    int num_pages_;
};

class PenHolder
{
  public:
    PenHolder(std::string name)
    {
      name_ = name;
      std::vector<Pen> tmp;
      pens_ = tmp;
    }

  private:
    std::string name_;
    std::vector<Pen> pens_;
};
