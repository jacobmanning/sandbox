#include <iostream>
#include <memory>

struct TreeNode
{
  enum Kind
  {
    RED,
    BLUE
  };

  Kind kind_;
  // TreeNode* left_;
  // TreeNode* right_;
  unique_ptr<TreeNode> left_ = nullptr;
  unique_ptr<TreeNode> right_ = nullptr;

  // TreeNode(Kind k, TreeNode* left=nullptr, TreeNode* right=nullptr)
  //   : kind_{k}, left_{left}, right_{right} {}
  // TreeNode(Kind k, unique_ptr<TreeNode> left=nullptr, unique_ptr<TreeNode> right=nullptr)
  //   : kind_{k}, left_{left}, right_{right} {}
  TreeNode(Kind k) : kind_{k}
  {
  }
};

template <typename Derived>
class GenericVisitor
{
public:
  // void visit_preorder(TreeNode* node)
  void visit_preorder(const unique_ptr<TreeNode>& node)
  {
    if (node)
    {
      dispatch_node(node);
      visit_preorder(node->left_);
      visit_preorder(node->right_);
    }
  }

  // void visit_inorder(TreeNode* node)
  void visit_inorder(const unique_ptr<TreeNode>& node)
  {
    if (node)
    {
      visit_inorder(node->left_);
      dispatch_node(node);
      visit_inorder(node->right_);
    }
  }

  // void visit_postorder(TreeNode* node)
  void visit_postorder(const unique_ptr<TreeNode>& node)
  {
    if (node)
    {
      visit_postorder(node->left_);
      visit_postorder(node->right_);
      dispatch_node(node);
    }
  }

  // void handle_red(TreeNode* node)
  void handle_red(const unique_ptr<TreeNode>& node)
  {
    std::cout << "Generic handle RED"
              << "\n";
  }

  // void handle_blue(TreeNode* node)
  void handle_blue(const unique_ptr<TreeNode>& node)
  {
    std::cout << "Generic handle BLUE"
              << "\n";
  }

private:
  Derived& derived()
  {
    return *static_cast<Derived*>(this);
  }

  // void dispatch_node(TreeNode* node)
  void dispatch_node(const unique_ptr<TreeNode>& node)
  {
    switch (node->kind_)
    {
      case TreeNode::Kind::RED:
        derived().handle_red(node);
        break;
      case TreeNode::Kind::BLUE:
        derived().handle_blue(node);
        break;
      default:
        assert(false);
    }
  }
};

class SpecialVisitor : public GenericVisitor<SpecialVisitor>
{
public:
  // void handle_red(TreeNode* node)
  void handle_red(const unique_ptr<TreeNode>& node)
  {
    std::cout << "RED is special!"
              << "\n";
  }
};

// void make_treenode(TreeNode* parent, bool left, TreeNode::Kind k)
void make_treenode(unique_ptr<TreeNode>& parent, bool left, TreeNode::Kind k)
{
  // auto next_node = TreeNode{k};

  if (left)
  {
    // parent->left_ = next_node;
    // parent->left_ = TreeNode{TreeNode::Kind::RED};
    parent->left_ = make_unique<TreeNode>{TreeNode::Kind::RED};
  }
  else
  {
    // parent->right_ = next_node;
    // parent->right_ = TreeNode{TreeNode::Kind::BLUE};
    parent->right_ = make_unique<TreeNode>{TreeNode::Kind::BLUE};
  }

  // return parent;
}

unique_ptr<TreeNode> make_tree(int num_nodes)
{
  // auto root = TreeNode{TreeNode::Kind::RED};
  auto root = make_unique<TreeNode>(TreeNode::Kind::RED);
  bool left = true;
  auto next_parent = root;

  for (int i = 0; i < num_nodes; ++i)
  {
    make_treenode(next_parent, left);
    // Increment left
    left = !left;
    if (next_parent->left_ != nullptr && next_parent->right_ != nullptr)
    {
    }
  }

  return root;
}

int main()
{
}
