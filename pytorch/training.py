import os
import torch
from modules import data_setup, engine, model_builder
from torchvision import transforms

NUM_EPOCHS = 20
BATCH_SIZE = 32
HIDDEN_UNITS = 20
LEARNING_RATE = 0.005


def main():

    training_dir = 'data/pizza_steak_sushi/train'
    test_dir = 'data/pizza_steak_sushi/test'

    data_transform = transforms.Compose([
        transforms.Resize((64, 64)),
        transforms.ToTensor()
    ])

    training_dataloader, test_dataloader, class_names = data_setup.create_dataloaders(training_dir,
                                                                                      test_dir,
                                                                                      data_transform,
                                                                                      batch_size=BATCH_SIZE, )
    model = model_builder.TinyVGG(input_shape=3,
                                  hidden_units=HIDDEN_UNITS,
                                  output_shape=len(class_names))

    loss_func = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(),
                                 lr=LEARNING_RATE)

    engine.train(model,
                 training_dataloader,
                 test_dataloader,
                 loss_func,
                 optimizer,
                 NUM_EPOCHS)


if __name__ == '__main__':
    main()
