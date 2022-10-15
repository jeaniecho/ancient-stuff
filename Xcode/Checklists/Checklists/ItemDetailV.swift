//
//  AddItemViewController.swift
//  Checklists
//
//  Created by 조예진 on 2018. 4. 1..
//  Copyright © 2018년 Mia Cho. All rights reserved.
//

import UIKit


protocol ItemDetailViewControllerDelegate: class {
    func ItemDetailViewControllerDidCancel(_ controller: ItemDetailV)
    func ItemDetailViewController(_ controller: ItemDetailV, didFinishAdding item: ChecklistItem)
    func ItemDetailViewController(_ controller: ItemDetailV, didFinishEditing item: ChecklistItem)
}

class ItemDetailV: UITableViewController, UITextFieldDelegate {

    @IBOutlet weak var textField: UITextField!
    @IBOutlet weak var cancelBarButton: UIBarButtonItem!
    @IBOutlet weak var doneBarButton: UIBarButtonItem!
    var itemToEdit: ChecklistItem?
    
    weak var delegate: ItemDetailViewControllerDelegate?
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        //textField.delegate = self
        
        if let item = itemToEdit {
            title = "Edit Item"
            textField.text = item.text
            doneBarButton.isEnabled = true
        }
    }
    
    /*
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return false
    }
    */
    
    override func viewWillAppear(_ animated: Bool) {
        textField.becomeFirstResponder()
    }
    
    @IBAction func cancel() {
        navigationController?.popViewController(animated: true)
        delegate?.ItemDetailViewControllerDidCancel(self)
    }
    
    @IBAction func done() {
        if let itemToEdit = itemToEdit {
            itemToEdit.text = textField.text!
            delegate?.ItemDetailViewController(self, didFinishEditing: itemToEdit)
        } else {
            let item = ChecklistItem()
            item.text = textField.text!
            item.checked = false
            delegate?.ItemDetailViewController(self, didFinishAdding: item)
        }
    }
    
    override func tableView(_ tableView: UITableView, willSelectRowAt indexPath: IndexPath) -> IndexPath? {
        return nil
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        
        let oldText = textField.text!
        let stringRange = Range(range, in:oldText)
        let newText = oldText.replacingCharacters(in: stringRange!, with: string)
        if newText.isEmpty {
            doneBarButton.isEnabled = false
        } else {
            doneBarButton.isEnabled = true
        }
        return true
    }
}
