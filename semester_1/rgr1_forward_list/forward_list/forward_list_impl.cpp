#include "forward_list_impl.h"

ForwardList::ForwardListIterator ForwardList::begin() {
    return ForwardListIterator(head_);
}

ForwardList::ForwardListIterator ForwardList::end() {
    return ForwardListIterator(nullptr);
}

ForwardList::ForwardListIterator ForwardList::begin() const {
    return ForwardListIterator(head_);
}

ForwardList::ForwardListIterator ForwardList::end() const {
    return ForwardListIterator(nullptr);
}

ForwardList::ForwardList() : head_(nullptr), size_(0) {}

ForwardList::ForwardList(size_t count, int32_t value)
    : head_(nullptr), size_(0) {
    for (size_t i = 0; i < count; ++i) {
        PushFront(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init)
    : head_(nullptr), size_(0) {
    for (auto it = std::rbegin(init); it != std::rend(init); ++it) {
        PushFront(*it);
    }
}

ForwardList::ForwardList(const ForwardList& rhs)
    : head_(nullptr), size_(0) {
    Node* cur = rhs.head_;
    Node* prev = nullptr;

    while (cur) {
        Node* node = new Node(cur->value_);
        if (!head_) {
            head_ = node;
        } else {
            prev->next_ = node;
        }
        prev = node;
        cur = cur->next_;
        ++size_;
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs) return *this;

    Clear();

    Node* cur = rhs.head_;
    Node* prev = nullptr;

    while (cur) {
        Node* node = new Node(cur->value_);
        if (!head_) {
            head_ = node;
        } else {
            prev->next_ = node;
        }
        prev = node;
        cur = cur->next_;
        ++size_;
    }

    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t value) {
    Node* node = new Node(value);
    node->next_ = head_;
    head_ = node;
    ++size_;
}

void ForwardList::PopFront() {
    if (!head_) return;

    Node* tmp = head_;
    head_ = head_->next_;
    delete tmp;
    --size_;
}

void ForwardList::Remove(int32_t value) {
    while (head_ && head_->value_ == value) {
        PopFront();
    }

    Node* cur = head_;
    while (cur && cur->next_) {
        if (cur->next_->value_ == value) {
            Node* tmp = cur->next_;
            cur->next_ = tmp->next_;
            delete tmp;
            --size_;
        } else {
            cur = cur->next_;
        }
    }
}

void ForwardList::Clear() {
    while (head_) {
        PopFront();
    }
}

bool ForwardList::FindByValue(int32_t value) {
    Node* cur = head_;
    while (cur) {
        if (cur->value_ == value) return true;
        cur = cur->next_;
    }
    return false;
}

void ForwardList::Print(std::ostream& out) {
    Node* cur = head_;
    while (cur) {
        out << cur->value_;
        if (cur->next_) {
            out << " ";
        }
        cur = cur->next_;
    }
}


int32_t ForwardList::Front() const {
    return head_->value_;
}

size_t ForwardList::Size() const {
    return size_;
}
